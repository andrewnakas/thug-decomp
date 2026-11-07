/* fuzzy: 80.6 */
struct Ring_001F5EB8 {
    int m_buf;
    int m_desc;
    int m_count;
    int m_head;
    int m_avail;
    int m_bytes;
    char pad18[0x28];
    int m_sema;
    int m_active;
};

extern char D_00366388[];
extern "C" void func_0031BCE0(int sema);
extern "C" void func_0031BCC0(int sema);
extern "C" void func_001E4BE8(char* fmt, ...);
extern "C" void func_001F5AF8(unsigned int chcr);
extern "C" int func_001F5A40(Ring_001F5EB8* r, unsigned int madr);
extern "C" void func_001F5B68(int desc, int buf, int id, int qwc);

int func_001F5EB8(Ring_001F5EB8* r)
{
    int started = 0;
    func_0031BCE0(r->m_sema);
    if (!r->m_active) {
        func_001E4BE8(D_00366388);
        return 0;
    }
    func_001F5AF8(5);
    unsigned int chcr = *(volatile unsigned int*)0x1000B400;
    int pos = func_001F5A40(r, *(volatile unsigned int*)0x1000B410);
    int n = r->m_count;
    int head = r->m_head;
    int done = (pos + n - head) % n;
    r->m_avail -= done;
    r->m_head = (head + done) % n;
    int t = r->m_head + r->m_avail;
    int idx = t % n;
    int blocks = r->m_bytes / 2048;
    r->m_bytes = r->m_bytes - (blocks << 11);
    if (blocks > 0) {
        int prev = (t + (n - 1)) % n;
        started = 1;
        func_001F5B68(r->m_desc + prev * 16, r->m_buf + (prev << 11), 3, 0x80);
    }
    for (int i = 0; i < blocks; i++) {
        func_001F5B68(r->m_desc + idx * 16, r->m_buf + (idx << 11), (i != blocks - 1) ? 3 : 0, 0x80);
        idx = idx + 1;
        idx = idx % r->m_count;
    }
    r->m_avail = r->m_avail + blocks;
    if (r->m_avail) {
        if (started) chcr = (chcr & 0x0FFFFFFF) | 0x30000000;
        func_001F5AF8(chcr | 0x100);
    }
    func_0031BCC0(r->m_sema);
    return 1;
}
