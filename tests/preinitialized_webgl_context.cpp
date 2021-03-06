#include <stdio.h>
#include <assert.h>
#include <emscripten/html5.h>
#include <GLES2/gl2.h>

int main()
{
  EmscriptenWebGLContextAttributes attrs;
  emscripten_webgl_init_context_attributes(&attrs);
  EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context = emscripten_webgl_create_context(0, &attrs);
  assert(context);
  EMSCRIPTEN_RESULT res = emscripten_webgl_make_context_current(context);
  assert(res >= 0);
  int activeTexture = 0;
  glGetIntegerv(GL_ACTIVE_TEXTURE, &activeTexture);
  printf("GL_ACTIVE_TEXTURE: %d\n", activeTexture - GL_TEXTURE0);
#ifdef REPORT_RESULT
  int result = activeTexture - GL_TEXTURE0;
  REPORT_RESULT(result);
#endif
}
