extern float D_00394148;
extern "C" void func_001F0370(char* s, void* a, int b, int c);

struct Mgr_0022D338 {
    void Tick(float t, float reset, float rate, char* script);
};

void Mgr_0022D338::Tick(float t, float reset, float rate, char* script)
{
    if (t > 0.01f && t <= reset) {
        if (t < D_00394148) {
            func_001F0370(script, 0, 0, 0);
            float d = D_00394148 / rate;
            if (d < 0.2f) {
                d = 0.2f;
            }
            D_00394148 = D_00394148 - d;
        }
    } else {
        D_00394148 = reset;
    }
}
