extern "C" int func_00142B18(void* table, int* key, int a);
extern "C" void func_00142250(void* obj, int* key);
extern "C" void func_00142B80(void* table, int* key, void* obj);

class Mgr_00142708 {
public:
    void* m0;
    virtual ~Mgr_00142708();
    virtual void* V1();
    void* Create(int* key, int unique);
};

void* Mgr_00142708::Create(int* key, int unique)
{
    void* obj = V1();
    if (obj) {
        if (unique) {
            int k = *key;
            while (func_00142B18(m0, &k, 0))
                k++;
            *key = k;
        }
        func_00142250(obj, key);
        func_00142B80(m0, key, obj);
    }
    return obj;
}
