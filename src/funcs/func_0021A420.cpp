extern float D_00387CDC;
extern char D_0038F758[];
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" float func_003412F0(float x);
extern "C" void func_001E7318(void* target, const char* name, float value);

struct Owner_0021A420 {
    char m_pad[0x18];
    void* m_18;
};

bool Script_0021A420(void* params, Owner_0021A420* owner)
{
    float value;
    func_001E7EB0(params, 0, &value, 1);
    float result = func_003412F0(value);
    func_001E7318(owner->m_18, D_0038F758, result * D_00387CDC);
    return true;
}
