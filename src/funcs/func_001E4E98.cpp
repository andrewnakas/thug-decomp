struct Ent_001E4E98 {
    char b[0x80];
};
extern Ent_001E4E98 D_00351E30[];
extern "C" int func_003331D0(Ent_001E4E98* e);

void Call_001E4E98(int i)
{
    func_003331D0(D_00351E30 + i);
}
