use gtk::prelude::*;
use gtk::{Application, ApplicationWindow};

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

        win.show_all();
    });

    app.run();
}
