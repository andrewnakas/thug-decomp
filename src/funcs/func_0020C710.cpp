extern unsigned int D_0038F37C;

extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" unsigned int func_0010FC30();

bool Cmd_0020C710(void* params, void* script)
{
    float t = 0.0f;
    func_001E7EB0(params, 0, &t, 0);
    unsigned int start = D_0038F37C;
    float elapsed = (float)(func_0010FC30() - start);
    return t * 1000.0f < elapsed;
}
