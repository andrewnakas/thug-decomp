class Shared_0010F168 {
public:
    int m_pad[5];
    virtual ~Shared_0010F168();
};

extern Shared_0010F168* D_00388CA4;
extern unsigned int D_00388CA8;

void Release_0010F168()
{
    if (D_00388CA8 > 1) {
        D_00388CA8--;
        return;
    }
    if (D_00388CA4)
        delete D_00388CA4;
    D_00388CA4 = 0;
    D_00388CA8 = 0;
}
