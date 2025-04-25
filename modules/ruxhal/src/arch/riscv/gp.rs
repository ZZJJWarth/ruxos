#[link_section = ".bss"]
static mut GP_POINTER:usize=0;
#[link_section = ".bss"]
static mut USER_GP_POINTER:usize=0;


pub fn resume_kernel_gp(){
    unsafe{
        if GP_POINTER == 0{
            return
        }else{
            core::arch::asm!(
                "mv {0}, gp
                mv gp, {1}",
                out(reg) USER_GP_POINTER,
                in(reg) GP_POINTER
            )
        }
    }

}

pub fn resume_user_gp(){
    unsafe{
        if USER_GP_POINTER == 0{
            return
        }else{
            core::arch::asm!(
                "mv {0}, gp
                mv gp, {1}",
                out(reg) GP_POINTER,
                in(reg) USER_GP_POINTER
            )
        }
    }
}

pub fn store_kernel_gp(){
    unsafe{
        core::arch::asm!{
            "mv {0},gp",
            out(reg) GP_POINTER
        }
    }
}


