class Goal_0023CFF0 {
public:
    char pad0[0x14];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool IsActive();
};

struct Mgr_0023CFF0 {
    int m0;
    char m4[1];
};

extern "C" int func_0023C040(Mgr_0023CFF0* self);
extern "C" Goal_0023CFF0* func_00243C18(void* list, int* index, unsigned int* key);
extern "C" void* func_00244528(Goal_0023CFF0* goal);
extern "C" bool func_001E8248(void* self, unsigned int name, void** out, int assert_);

bool func_0023CFF0(Mgr_0023CFF0* self)
{
    int i;
    unsigned int key;
    void* arr;

    for (i = 0; i < func_0023C040(self); i++) {
        Goal_0023CFF0* goal = func_00243C18(self->m4, &i, &key);
        if (goal->IsActive()) {
            void* params = func_00244528(goal);
            arr = 0;
            if (func_001E8248(params, 0x52D4489E, &arr, 0))
                return true;
        }
    }
    return false;
}
