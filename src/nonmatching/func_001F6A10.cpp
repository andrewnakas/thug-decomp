/* fuzzy: 95.7 */
/* blocked: the game cross-jumps the two `printf(msg, path); return 0;` tails (shared jal, nop in the delay slot);
   ours keeps both; goto/msg form and a void printf do not. */
extern "C" char* func_00336208(char*, int);
extern "C" void func_00332088(char*, char*, int);
extern "C" int func_00331950(char*, char*);
extern "C" int func_00331BB8(char*);
extern "C" int func_003331D0(char*, char*, ...);
extern "C" int func_00103F28(char*, ...);
extern "C" void func_003288E0(int);
extern "C" void func_003291C0(int);
extern "C" int func_00328DB8(int);
extern "C" void func_00329388(int, int, unsigned int);
extern "C" int func_00328438(void*, char*);
extern "C" void func_003293B8(int, char*);
extern "C" int func_0031E880(char*, int);
extern "C" int func_0031EC88(int, int, int);
extern "C" void func_0031EB08(int);

extern char D_0038EA18[];
extern char D_0038EA20[];
extern char D_0038EA28[];
extern char D_0038EA30[];
extern char D_0038EA38[];
extern unsigned char D_00385971[];
extern char D_003663A0[];
extern char D_003663B0[];
extern char D_003663D8[];
extern char D_003663F8[];
extern char D_00366418[];
extern int D_0038881C;
extern int D_0038EA14;

extern int D_0038EA40[];

struct File_001F6A10 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m_pad[7];
    int m2C;
    int m30;
};

int func_001F6A10(File_001F6A10* f, char* name, int size)
{
    char path[256];
    char dev[64];
    char buf[16];
    char* msg;
    int fd;
    int sz;
    char* colon = func_00336208(name, ':');
    if (colon) {
        int len = colon - name;
        func_00332088(dev, name, len);
        colon++;
        dev[len] = 0;
        if (func_00331950(dev, D_0038EA18) == 0) {
            int n = func_00331BB8(colon);
            f->m0 = 1;
            for (int i = 0; i < n; i++) {
                if (colon[i] == '/')
                    colon[i] = '\\';
                int c = colon[i];
                int r = c - 0x20;
                if (!(D_00385971[c] & 2))
                    r = c;
                colon[i] = r;
            }
            char* ext;
            if (func_00336208(name, ';'))
                ext = D_0038EA20;
            else
                ext = D_0038EA28;
            func_003331D0(path, D_0038EA30, colon, ext);
        } else {
            f->m0 = 0;
            func_003331D0(path, D_0038EA38, dev, colon + 1);
        }
    } else {
        *(int*)dev = D_0038EA40[0];
        ((unsigned short*)dev)[2] = ((unsigned short*)D_0038EA40)[2];
        f->m0 = 0;
        func_003331D0(path, D_0038EA38, dev, name);
    }
    func_00103F28(D_003663A0, path);
    if (f->m0) {
        if (!D_0038881C && !D_0038EA14) {
            func_003288E0(0);
            func_003291C0(2);
            func_00328DB8(0);
            D_0038EA14 = 1;
        }
        f->m2C = size;
        func_00329388(0x50, 5, ((unsigned int)(size + 15) >> 4) << 4);
        if (!func_00328438(&f->m8, path)) {
            func_00103F28(D_003663B0, path);
            return 0;
        }
        f->m4 = f->mC;
        buf[0] = 0;
        buf[1] = 0;
        buf[2] = 0;
        func_003293B8(f->m8, buf);
        return 1;
    }
    fd = func_0031E880(path, 1);
    f->m30 = fd;
    if (fd < 0) {
        func_00103F28(D_003663D8, path);
        return 0;
    }
    sz = func_0031EC88(fd, 0, 2);
    f->m4 = sz;
    if (sz < 0) {
        func_00103F28(D_003663F8, path, sz);
    } else {
        if (func_0031EC88(f->m30, 0, 0) >= 0)
            return 1;
        func_00103F28(D_00366418, path);
    }
    func_0031EB08(f->m30);
    return 0;
}
