use core::ffi::{c_int, c_long, c_void};

use ruxtask::current;

pub fn sys_brk(brk:*mut c_void)->c_long{
    debug!("sys_brk <= brk:{:x}",brk as usize);
    syscall_body!(brk,{

        let mut c = current();
        let brk = brk as usize;
        let mut heap_brk = c.brk.lock();
        if let None = heap_brk.inited(){
            heap_brk.init();
        }

        if brk == 0{
            return Ok(heap_brk.get_end());
        }

        heap_brk.brk(brk);


        return Ok(heap_brk.get_end());
    })
}