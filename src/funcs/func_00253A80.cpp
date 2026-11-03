class Shared_00253A80 {
public:
    int m_pad[5];
    virtual ~Shared_00253A80();
};

extern Shared_00253A80* D_00390828;
extern unsigned int D_0039082C;

void Release_00253A80()
{
    if (D_0039082C > 1) {
        D_0039082C--;
        return;
    }
    if (D_00390828)
        delete D_00390828;
    D_00390828 = 0;
    D_0039082C = 0;
}
