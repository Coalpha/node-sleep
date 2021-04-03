#include <cstdint>
#include <thread>
#include <chrono>
using namespace std;

#include <napi.h>
using namespace Napi;

template <class duration>
inline Value sleep(CallbackInfo const &info) noexcept {
   Env const env{info.Env()};

   do {
      if (info.Length() != 1)
         break;
      auto const &arg{info[0]};
      if (!arg.IsNumber())
         break;
      int32_t val{arg.As<Number>().Int32Value()};
      if (val < 0)
         break;
      this_thread::sleep_for(duration{val});
      goto ret;
   } while (false);

   TypeError::New(env, "Expected one uint argment!").ThrowAsJavaScriptException();

   ret: return env.Undefined();
}

Object init_all(Env const env, Object exports) {
   using namespace chrono;
   exports.Set("sleep_ns", Function::New(env, sleep<nanoseconds> , "sleep_ns"));
   exports.Set("sleep_ms", Function::New(env, sleep<milliseconds>, "sleep_ms"));
   exports.Set("sleep_s" , Function::New(env, sleep<seconds>     , "sleep_s" ));
   exports.Set("sleep_m" , Function::New(env, sleep<minutes>     , "sleep_m" ));
   exports.Set("sleep_h" , Function::New(env, sleep<hours>       , "sleep_h" ));

   return exports;
}

NODE_API_MODULE(node_sleep, init_all)
