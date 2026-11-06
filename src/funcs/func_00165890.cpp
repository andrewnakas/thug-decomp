/* sym: PsmIndex001657A0__Fi = 0x001657A0 */
struct Limits_00165890 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

extern Limits_00165890 D_00360AE0[];
int PsmIndex001657A0(int psm);

struct Obj_00165890 {
    int Fn(int w, int h, int psm);
};

int Obj_00165890::Fn(int w, int h, int psm)
{
    Limits_00165890* t = &D_00360AE0[PsmIndex001657A0(psm)];
    return (w / t->m8) * (h / t->mC);
}
