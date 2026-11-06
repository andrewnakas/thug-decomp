extern "C" void* func_001A0718(void* self);
extern "C" void func_001197A8(void* p, float f);
struct Obj_001A0AF0 { void Set(float f); };
void Obj_001A0AF0::Set(float f) { void* p = func_001A0718(this); if (p) func_001197A8(p, f); }
