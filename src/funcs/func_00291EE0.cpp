extern char D_003770C0[];
extern char D_003770E8[];
extern char D_00377110[];
extern char D_00377138[];
extern char D_00377160[];
extern char D_00377188[];
extern char D_003771B8[];
extern char D_003771E8[];
extern char D_00377218[];

char* func_00291EE0(unsigned int key, unsigned int n)
{
    char* p = 0;
    switch (key) {
    case 0x54166ACD:
        switch (n) {
        case 0: p = D_003770C0; break;
        case 1: p = D_003770E8; break;
        case 2: p = D_00377110; break;
        case 3: p = D_00377138; break;
        case 4: p = D_00377160; break;
        }
        break;
    case 0x4EC3CFB5:
        switch (n) {
        case 0: p = D_00377188; break;
        case 1: p = D_003771B8; break;
        case 2: p = D_003771E8; break;
        case 3: p = D_00377218; break;
        case 4: p = D_003771B8; break;
        }
        break;
    }
    return p;
}
