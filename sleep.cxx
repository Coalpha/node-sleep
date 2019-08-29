#include <napi.h>
#include <thread>
#include <chrono>

#define makesleep(ext, unit) \
Napi::Value sleep_ ## ext(const Napi::CallbackInfo &info) { \
   Napi::Env env = info.Env(); \
   long long time(0); \
   if ( \
      info.Length() != 1 \
      || !info[0].IsNumber() \
      || (time = info[0].As<Napi::Number>().Int32Value()) < 0 \
   ) { \
      Napi::TypeError::New(env, "Expected a positive integer!") \
         .ThrowAsJavaScriptException(); \
   } else { \
      std::this_thread::sleep_for(std::chrono::unit(time)); \
   } \
   return env.Undefined(); \
}

#define export(ext) \
exports.Set("sleep_" # ext, Napi::Function::New(env, node_sleep::sleep_ ## ext));

namespace node_sleep {
   makesleep(ms, milliseconds)
   makesleep(s, seconds)
   makesleep(m, minutes)
   makesleep(h, hours)
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
   export(ms)
   export(s)
   export(m)
   export(h)
   return exports;
}

NODE_API_MODULE(testaddon, InitAll)
