extern "C" bool func_001E8708(void* params, unsigned int name);

extern "C" bool func_001313B0(int* mode, void* params)
{
    *mode = 0;
    if (func_001E8708(params, 0x4F792E6C)) {
        *mode = 1;
    } else if (func_001E8708(params, 0x3153E314)) {
        *mode = 2;
    } else if (func_001E8708(params, 0x6D941203)) {
        *mode = 3;
    }
    return true;
}
