class Base_0023C048 {
public:
    char pad0[0x14];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool IsActive();
    virtual bool IsSelected();
};

struct Mgr_0023C048 {
    int m0;
    char m4[1];
};

extern "C" int func_0023C040(Mgr_0023C048* self);
extern "C" Base_0023C048* func_00243C18(void* list, int* index, unsigned int* key);
extern "C" bool func_00246C60(Base_0023C048* goal);

int func_0023C048(Mgr_0023C048* self, bool active)
{
    int i;
    unsigned int key;

    int count = 0;
    for (i = 0; i < func_0023C040(self); i++) {
        Base_0023C048* goal = func_00243C18(self->m4, &i, &key);
        if (func_00246C60(goal) && !active)
            continue;
        if (active && goal->IsActive())
            count++;
        else if (goal->IsSelected())
            count++;
    }
    return count;
}
