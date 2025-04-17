// use std::thread::current;

use core::usize;

use alloc::sync::Arc;

use crate::{current, vma::Vma};
pub struct BrkHeap{
    heap_end:usize,
    heap_start:usize,
    heap_area:Option<Vma>
}


impl BrkHeap{

    pub fn new()->Self{
        Self { heap_end: 0, heap_start: 0, heap_area: None }
    }

    pub fn init(&mut self){
        self.heap_end = 0xffff_ffc7_0000_0000;
        self.heap_start = 0xffff_ffc7_0000_0000;
        let heap = Vma::new(-1, 0, 0x1|0x2, 0x20|0x02);
        self.heap_area = Some(heap);
        self.sync_vma();
    }

    pub fn inited(&self)->Option<Vma>{
        self.heap_area.clone()
    }

    pub fn brk(&mut self,addr:usize){
        self.heap_end = addr;
        self.sync_vma();
    }

    pub fn get_end(&self)->usize{
        self.heap_end
    }
}

impl BrkHeap{
    fn sync_vma(&mut self){
        let c = current();
        let mut vma_map = c.mm.vma_map.lock();
        let heap=self.heap_area.as_mut().unwrap();
        heap.end_addr=self.heap_end;
        heap.start_addr=self.heap_start;
        if let Some(h) = vma_map.get_mut(&self.heap_start){
            *h=self.heap_area.clone().unwrap();
            return;
        }
        vma_map.insert(self.heap_start, self.heap_area.clone().unwrap());
        return;

    }
}