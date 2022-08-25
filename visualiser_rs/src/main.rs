use gtk::prelude::*;
use gtk::{Application, ApplicationWindow, Label};
use gtk;
use gtk::traits::*;

fn main() {
    let app = Application::builder()
        .application_id("com.whythis.FillerVisualiser")
        .build();

    app.connect_activate(|app| {
        let win = ApplicationWindow::builder()
            .application(app)
            .default_width(700)
            .default_height(700)
            .title("Filler Visualiser")
            .build();
        let title = Label::new(Some("Filler Logo\n\tand\nPlay Button"));
            win.add(&title);
        //  in order to add more than one widget
        //  we need to create a box first

        //let button = gtk::Button::with_label("PLAY");
        //  win.add(&button);

        win.show_all();
        // Presss 'Esc' to close windonw
/*        win.connect_key_press_event(move |_, key| {
            match key.keyval as i32 {
                key::Escape => gtk::main_quit(),
                _ => ()
            }
            gtk::signal::Inhibit(false)
        }); */
    });

    app.run();
}
