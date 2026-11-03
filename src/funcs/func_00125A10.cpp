struct Arr_00125A10 {
    char pad[0x8];
    int m_type;
};

struct C_00125A10 {
    int GetPair(void* params, unsigned int id, float* a, float* b);
};

extern "C" int func_001E8248(void* params, unsigned int id, Arr_00125A10** out, int req);
extern "C" float func_001E9298(Arr_00125A10* a, int i);
extern "C" unsigned int func_001E9300(Arr_00125A10* a, int i);

int C_00125A10::GetPair(void* params, unsigned int id, float* a, float* b)
{
    Arr_00125A10* arr;
    if (func_001E8248(params, id, &arr, 0)) {
        switch (arr->m_type) {
        case 2:
            *a = func_001E9298(arr, 0);
            *b = func_001E9298(arr, 1);
            break;
        case 13: {
            float v[2];
            for (int i = 0; i < 2; i++) {
                unsigned int n = func_001E9300(arr, i);
                if (n == 0x85981897 || n == 0xE126E035)
                    v[i] = -1.0f;
                else if (n == 0x4B358AEB || n == 0x76A08D5B)
                    v[i] = 1.0f;
                else
                    v[i] = 0.0f;
            }
            *a = v[0];
            *b = v[1];
            break;
        }
        }
        return 1;
    }
    return 0;
}
