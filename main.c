//
// Created by swansky on 13/03/2022.
//
#include <stdio.h>
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>


EM_BOOL mouse_callback(int eventType, const EmscriptenMouseEvent *e, void *userData) {
    printf(" screen: (%ld,%ld), client: (%ld,%ld),%s%s%s%s button: %hu, buttons: %hu, movement: (%ld,%ld), target: (%ld, %ld)\n",
           e->screenX, e->screenY, e->clientX, e->clientY,
           e->ctrlKey ? " CTRL" : "", e->shiftKey ? " SHIFT" : "", e->altKey ? " ALT" : "", e->metaKey ? " META" : "",
           e->button, e->buttons, e->movementX, e->movementY, e->targetX, e->targetY);
    return 0;
}

EM_BOOL key_callback(int eventType, const EmscriptenKeyboardEvent *e, void *userData) {

    printf("%s\n",e->key);
/*    printf(" key: \"%s\", code: \"%s\", location: %lu,%s%s%s%s repeat: %d, locale: \"%s\", char: \"%s\", charCode: %lu, keyCode: %lu, which: %lu, timestamp: %lf\n",
           e->key, e->code, e->location,
           e->ctrlKey ? " CTRL" : "", e->shiftKey ? " SHIFT" : "", e->altKey ? " ALT" : "", e->metaKey ? " META" : "",
           e->repeat, e->locale, e->charValue, e->charCode, e->keyCode, e->which,
           e->timestamp);*/

return 0;
}

int main() {
    printf("Hello World je suis un test\n");
    emscripten_set_keydown_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, key_callback);
    emscripten_set_click_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, mouse_callback);
}

#ifdef __cplusplus
extern "C" {
#endif

EMSCRIPTEN_KEEPALIVE void myFunction(int argc, char **argv) {
    printf("MyFunction Called\n");
}

EMSCRIPTEN_KEEPALIVE void test(int argc, char **argv) {
    printf("MyFunction Called test\n");
}

EMSCRIPTEN_KEEPALIVE int multiply(int argc) {
    return argc * 2;
}


#ifdef __cplusplus
}
#endif