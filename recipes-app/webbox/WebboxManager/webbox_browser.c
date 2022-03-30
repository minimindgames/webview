#include <stdio.h>
#include <unistd.h>

#include "webbox_module.h"

static bool module_init(int manager_socket) {
    if (execl("/usr/bin/firefox", "firefox", "-headless", NULL) == -1) {
        perror("execl");
    }
    return false;
}

webbox_module webbox_browser = {
    .name = __FILE__,
    .init = module_init,
};
