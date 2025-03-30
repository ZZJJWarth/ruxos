use core::ops::Add;

use driver_virtio::PhysAddr;

use crate::arch;

const PPN_MASK:usize = 0xffff_ffff_fff0_0000;

pub enum SatpMode{
    Bare,
    Sv39,
    Sv48,
    Sv57,
    Sv64,
}

impl From<SatpMode> for usize{
    fn from(value: SatpMode) -> Self {
        let value=match SatpMode{
            SatpMode::Bare=>{
                0
            }
            SatpMode::Sv39=>{
                8
            }
            SatpMode::Sv48=>{
                9
            }
            SatpMode::Sv57=>{
                10
            }SatpMode::Sv64=>{
                11
            }
        };
        value<<60
    }
}

pub struct PPN(usize);

impl From<PhysAddr> for PPN{
    fn from(value: PhysAddr) -> Self {
        let num = value;
        let page_frame_num = (num&PPN_MASK)>>20;
        Self(page_frame_num)
    }
}

impl From<PPN> for usize{
    fn from(value: PPN) -> Self {
        value.0
    }
}
pub struct AddressSpaceID(usize);


impl From<u16> for AddressSpaceID{
    fn from(value: u16) -> Self {
        let value = usize::from(value);
        AddressSpaceID(value<<44)
    }
}

impl From<AddressSpaceID> for usize{
    fn from(value: AddressSpaceID) -> Self {
        value.0
    }
}

pub struct RegSatp(usize);

impl RegSatp{
    pub fn new(mode:SatpMode,asid:u16,page_table_addr:PhysAddr)->RegSatp{
        let satp:usize = mode.into()&asid.into()&page_table_addr.into();
        RegSatp(satp)
    }

    pub unsafe fn write_satp(&self){
        unsafe {
            arch::riscv::asm!{
                "
                    csrw satp {}
                    sfence.vma
                ",
                in(reg) self.0
            }
        }
    } 
}

