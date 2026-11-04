extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" float func_00131268(int v);

extern "C" bool func_00131430(float* outX, float* outY, void* params, float w, float h)
{
    float x = 0.0f;
    float y = h;
    unsigned int xa = 0;
    if (func_001E8398(params, 0x46E55E8F, &xa, 0)) {
        switch (xa) {
        case 0xFF03CC4E:
            x = h;
            break;
        case 0x6086AA70:
            break;
        case 0x230CCBF4:
            x = w;
            break;
        case 0x617FE530:
            x = h * 0.5f;
            break;
        }
    }
    unsigned int ya = 0;
    if (func_001E8398(params, 0x28782D3B, &ya, 0)) {
        switch (ya) {
        case 0x6086AA70:
            y = 0.0f;
            break;
        case 0x230CCBF4:
            y = w;
            break;
        case 0x617FE530:
            y = h * 0.5f;
            break;
        case 0xFF03CC4E:
            y = h;
            break;
        }
    }
    float fx = 0.0f;
    if (func_001E7EB0(params, 0x46E55E8F, &fx, 0)) {
        if (func_001E8708(params, 0xD029F619))
            x = fx;
        else
            x = func_00131268((int)fx);
    }
    float fy = 0.0f;
    if (func_001E7EB0(params, 0x28782D3B, &fy, 0)) {
        if (func_001E8708(params, 0xD029F619))
            y = fy;
        else
            y = func_00131268((int)fy);
    }
    if (func_001E8708(params, 0xF8CFD515)) {
        float t = x;
        x = y;
        y = t;
    }
    *outX = x;
    *outY = y;
    return true;
}
