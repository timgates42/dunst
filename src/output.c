#include "output.h"

#include "log.h"
#include "x11/x.h"
#include "x11/screen.h"
/* #include "wayland/wl.h" */ // Not yet

const bool is_running_wayland(void){
        char* wayland_display = getenv("WAYLAND_DISPLAY");
        return !(wayland_display == NULL);
}

const struct output output_x11 = {
        x_setup,
        x_free,

        x_win_create,
        x_win_destroy,

        x_win_show,
        x_win_hide,

        x_display_surface,
        x_win_visible,
        x_win_get_context,

        get_active_screen,

        x_is_idle,
        have_fullscreen_window
};

/* const struct output output_wl = { */
        /* wl_init, */
        /* wl_deinit, */

        /* wl_win_create, */
        /* wl_win_destroy, */

        /* wl_win_show, */
        /* wl_win_hide, */

        /* wl_display_surface, */
        /* wl_win_visible, */
        /* wl_win_get_context, */

        /* wl_get_active_screen, */

        /* wl_is_idle, */
        /* wl_have_fullscreen_window */
/* }; */

const struct output* output_create(void)
{
        if (is_running_wayland()) {
                LOG_I("System is running wayland");
        } else{
                LOG_I("System is running X11");
        }
        return &output_x11;
}
/* vim: set ft=c tabstop=8 shiftwidth=8 expandtab textwidth=0: */
