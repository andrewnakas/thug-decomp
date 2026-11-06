struct Rec_001423F0 {
    unsigned char b[4];
};

class Obj_001423F0 {
public:
    char pad[0x128];
    Rec_001423F0 m_recs[1];
    void SetRec(int i, const Rec_001423F0* r);
};

void Obj_001423F0::SetRec(int i, const Rec_001423F0* r)
{
    m_recs[i] = *r;
}
