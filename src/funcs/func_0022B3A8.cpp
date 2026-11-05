extern "C" bool func_001F0900(unsigned int script);
extern "C" void* func_001F0750(unsigned int script, void* params, void* object, int a, int b, int c, int d, int e, int f, int g);

void* Spawn_0022B3A8(unsigned int script)
{
    if (func_001F0900(script)) {
        return func_001F0750(script, 0, 0, 0, -1, 0, 0, 0, 0, 0);
    }
    return 0;
}
