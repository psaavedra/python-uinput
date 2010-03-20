#include <err.h>
#include <string.h>

#include <suinput.h>

int main(void)
{
        int uinput_fd;
        int keys[] = {KEY_E, KEY_H, KEY_L, KEY_O};
        struct uinput_user_dev user_dev;

        memset(&user_dev, 0, sizeof(struct uinput_user_dev));
        strcpy(user_dev.name, "hello-driver");

        uinput_fd = suinput_uinput_open();

        if (uinput_fd == -1)
                err(1, "suinput_uinput_open");

        /* Error handling is omitted to keep code as readible as possible. */

        suinput_uinput_set_capabilities(uinput_fd, EV_KEY, keys, 4);
        suinput_uinput_create(uinput_fd, &user_dev);

        suinput_uinput_write(uinput_fd, EV_KEY, KEY_H, 1); /* press */
        suinput_uinput_write(uinput_fd, EV_KEY, KEY_H, 0); /* release */
        suinput_uinput_write(uinput_fd, EV_KEY, KEY_E, 1); /* press */
        suinput_uinput_write(uinput_fd, EV_KEY, KEY_E, 0); /* release */
        suinput_uinput_write(uinput_fd, EV_KEY, KEY_L, 1); /* press */
        suinput_uinput_write(uinput_fd, EV_KEY, KEY_L, 0); /* release */
        suinput_uinput_write(uinput_fd, EV_KEY, KEY_L, 1); /* press */
        suinput_uinput_write(uinput_fd, EV_KEY, KEY_L, 0); /* release */
        suinput_uinput_write(uinput_fd, EV_KEY, KEY_O, 1); /* press */
        suinput_uinput_write(uinput_fd, EV_KEY, KEY_O, 0); /* release */

        suinput_uinput_destroy(uinput_fd);

        return 0;
}
