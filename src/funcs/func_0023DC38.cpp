class Obj_0023DC38 {
public:
    char pad0[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual int Matches(int crc);
};

class Ent_0023DC38 : public Obj_0023DC38 {
public:
    char pad18[0x30 - 0x18];
    int* m30;
};

struct Self_0023DC38;
extern "C" int func_0023C040(Self_0023DC38* s);
extern "C" Ent_0023DC38* func_00243C18(void* table, int* idx, int* pos);

struct Self_0023DC38 {
    int m0;
    char m4[0x1C];

    int CountMatching(int crc);
};

int Self_0023DC38::CountMatching(int crc)
{
    int count = 0;
    int i = 0;
    while (i < func_0023C040(this)) {
        int pos;
        Ent_0023DC38* e = func_00243C18(m4, &i, &pos);
        if (*e->m30 == 0 && e->Matches(crc))
            count++;
        i++;
    }
    return count;
}
