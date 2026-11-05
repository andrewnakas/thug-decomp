struct Hook_002093C0 {
    char pad0[0x20];
    void (*m20)(Hook_002093C0* h);
};
struct Obj_002093C0 {
    char pad0[0x50];
    Hook_002093C0* m50;
    void Run();
};

void Obj_002093C0::Run()
{
    m50->m20(m50);
}
