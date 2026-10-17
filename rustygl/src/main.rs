use std::ffi::CStr;

use gl33::*;
use glfw::*;
use trustme::trustme;

fn main() {
    let mut glfw = glfw::init(glfw::fail_on_errors).unwrap();
    glfw.window_hint(WindowHint::ContextVersion(3, 3));
    glfw.window_hint(WindowHint::OpenGlProfile(OpenGlProfileHint::Core));
    #[cfg(target_os = "macos")]
    {
        glfw.window_hint(glfw::WindowHint::OpenGlForwardCompat(true));
    }
    let (mut window, events) = glfw
        .create_window(800, 600, "🦀🦀🦀", glfw::WindowMode::Windowed)
        .unwrap();
    window.make_current();
    unsafe {
        gl33::global_loader::load_global_gl(&|symbol| {
            let c_str = CStr::from_ptr(symbol as *const std::os::raw::c_char);
            let str_slice = c_str.to_str().unwrap_or("");
            window.get_proc_address(str_slice).unwrap()
        });
    }

    // Now functions are available globally
    unsafe {
        gl33::global_loader::ClearColor(0.2, 0.3, 0.3, 1.0);
    }
    while !window.should_close() {
        window.swap_buffers();
        glfw.poll_events();
        for (_, event) in glfw::flush_messages(&events) {
            match event {
                glfw::WindowEvent::Key(Key::Escape, _, Action::Press, _) => {
                    window.set_should_close(true);
                }
                _ => {}
            }
        }
    }
}
