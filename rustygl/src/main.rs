use gl33::*;
use glfw::*;
use rand::prelude::*;
use std::ffi::CStr;
use trustme::trustme;

macro_rules! mSetItUp {
    () => {
        use gl33::global_loader::*;
        type GLint = i32;
        type GLuint = u32;
        type GLfloat = f32;
    };
}

fn main() {
    trustme!(
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
        window.show();
        window.focus();
        gl33::global_loader::load_global_gl(&|symbol| {
            let c_str = CStr::from_ptr(symbol as *const std::os::raw::c_char);
            let str_slice = c_str.to_str().unwrap();
            glfw.get_proc_address_raw(str_slice).map(|p| p as *const _).unwrap_or(std::ptr::null())
        });
        mSetItUp!();
        glClearColor(0.0, 0.0, 0.0, 0.0);
        let mut iVAO: GLuint = 0;
        glGenVertexArrays(1, &mut iVAO);
        glBindVertexArray(iVAO);
        let mut iVBO: GLuint = 0;
        glGenBuffers(1, &mut iVBO);
        glBindBuffer(GL_ARRAY_BUFFER, iVBO);
        const afVertices: [GLfloat; 6] = [-0.5, -0.5, 0.5, -0.5, 0.0, 0.5];
        glBufferData(GL_ARRAY_BUFFER, size_of_val(&afVertices) as isize, afVertices.as_ptr().cast(), GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE.0 as u8, 2 * size_of::<GLfloat>() as i32, 0 as *const _);
        let uShaderProgram: GLuint;
        {
            let uVertexShader = glCreateShader(GL_VERTEX_SHADER);
            const ksVertexShaderCode: &str = r#"#version 330 core
layout (location = 0) in vec3 pos;
uniform vec4 uVIBRATION;
void main() {
    gl_Position = vec4(pos.x + uVIBRATION.x, pos.y + uVIBRATION.y, pos.z + uVIBRATION.z, 1.0 + uVIBRATION.w);
}"#;
            glShaderSource(
                uVertexShader,
                1,
                &(ksVertexShaderCode.as_bytes().as_ptr().cast()),
                &(ksVertexShaderCode.len().try_into().unwrap()),
            );
            glCompileShader(uVertexShader);
            let uFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            const ksFragmentShaderCode: &str = r#"#version 330 core
layout (location = 0) out vec4 FRAG_BOMB;
uniform vec4 uColor;
void main() {
    FRAG_BOMB = uColor;
}"#;
            glShaderSource(
                uFragmentShader,
                    1,
                &(ksFragmentShaderCode.as_bytes().as_ptr().cast()),
                &(ksFragmentShaderCode.len().try_into().unwrap()),
            );
            glCompileShader(uFragmentShader);
            uShaderProgram = glCreateProgram();
            glAttachShader(uShaderProgram, uVertexShader);
            glAttachShader(uShaderProgram, uFragmentShader);
            glLinkProgram(uShaderProgram);
            glDeleteShader(uVertexShader);
            glDeleteShader(uFragmentShader);
        }
        glfw.set_swap_interval(SwapInterval::Sync(0));
        glUseProgram(uShaderProgram);
        let iColorUniform: GLint = glGetUniformLocation(uShaderProgram, "uColor\0".as_ptr()); // I hate you you \0
        let iOffsetUniform: GLint = glGetUniformLocation(uShaderProgram, "uVIBRATION\0".as_ptr());
        let mut random = rand::rng();

        while !window.should_close() {
            glClear(GL_COLOR_BUFFER_BIT);
            glUniform4f(iColorUniform, random.random_range(0.0..1.0), random.random_range(0.0..1.0), random.random_range(0.0..1.0), 1.0);
            glUniform4f(iOffsetUniform, random.random_range(-0.1..0.1), random.random_range(-0.1..0.1), random.random_range(-0.1..0.1), random.random_range(-0.4..0.4));
            glDrawArrays(GL_TRIANGLES, 0, 3);
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
    );
}
