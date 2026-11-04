extern "C" int func_001E7C80(void* params, unsigned int name, const char** out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" char* func_00332088(char* dst, const char* src, int n);

struct C_001BC628 {
    int m_pad[7];
    char m1C[64];
    int m5C;
    float m60;
    unsigned int m64;
    void Init(void* params);
};

void C_001BC628::Init(void* params)
{
    const char* str;
    if (func_001E7C80(params, 0x61414D56, &str, 0)) func_00332088(m1C, str, 0x40);
    func_001E7DE8(params, 0x99A9B716, &m5C, 0);
    func_001E7EB0(params, 0x14975800, &m60, 0);
    func_001E8398(params, 0x727F9552, &m64, 0);
}
