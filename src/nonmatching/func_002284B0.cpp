/* fuzzy: 74.3 */
/* sym: __9Prm_284B0 = 0x001E6978 */
/* sym: _$_9Prm_284B0 = 0x001E6AE8 */
/* sym: _vt$14ListHead_284B0 = 0x003724F8 */
/* sym: _vt$14ListNode_284B0 = 0x0035C0E0 */
extern char D_00372388[];
extern char D_003723A0[];
extern char D_003723B8[];
extern char D_003723D0[];
extern char D_0038FA38[];
extern char D_003721E8[];
extern char D_0038FA40[];
extern char D_0038FA48[];
extern char D_0038FA50[];
extern char D_0038FA58[];
extern char D_0038FA60[];
extern char D_0038FA68[];
extern char D_0038FA70[];
extern char D_0038FA78[];
extern char D_0038F9E8[];
extern char D_003723E0[];
extern char D_00372228[];
extern char D_0038FA20[];
extern char D_003722E0[];
extern char D_003723F8[];
extern char D_00372408[];
extern int D_00388814;
extern void* D_00388EFC;

extern "C" void* func_001190D0(int n);

// Script structure (constructed by 0x001E6978, destroyed by 0x001E6AE8).
struct Prm_284B0 {
    int m0;
    int m4;
    Prm_284B0();
    ~Prm_284B0();
    static void* operator new(unsigned int size) { return func_001190D0(size); }
};

// Memory card directory entry.
struct CardFile_284B0 {
    char pad0[0x18];
    char m_name[0x28];
    unsigned char m_sec;
    unsigned char m_min;
    unsigned char m_hour;
    unsigned char m_day;
    unsigned char m_month;
    char pad45;
    unsigned short m_year;
};

// Saved file header read from the start of each file.
struct SaveHeader_284B0 {
    int m0;
    unsigned int m_checksum;
    int m_size;
    int mC;
    int m_version;
    char m_data[0x64];
};
extern SaveHeader_284B0 D_003F5910;

class File_284B0 {
public:
    char pad0[0x14];
    virtual ~File_284B0();
};

class ListNode_284B0 {
public:
    int m0;
    CardFile_284B0* m_data;
    int m8;
    ListNode_284B0* m_next;
    ListNode_284B0* m_prev;
    ListNode_284B0(CardFile_284B0* d) : m_data(d), m8(0), m_next(this), m_prev(this) {}
    virtual ~ListNode_284B0()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
    virtual void Run();
    ListNode_284B0* Valid() { return ~(unsigned int)m_data ? this : 0; }
};

class ListHead_284B0 : public ListNode_284B0 {
public:
    ListHead_284B0() : ListNode_284B0((CardFile_284B0*)-1) {}
    virtual ~ListHead_284B0() {}
    virtual void Run();
    ListNode_284B0* First() { return m_next->Valid(); }
};

extern "C" int func_00106810();
extern "C" void* func_00112FB8(void* mc, int a, int b);
extern "C" File_284B0* func_00113380(void* card, const char* name, int mode, int a);
extern "C" void func_00113430(void* card, const char* mask, ListHead_284B0* out);
extern "C" void func_00113988(File_284B0* f);
extern "C" int func_001139D8(File_284B0* f, int off, int whence);
extern "C" int func_00113B10(File_284B0* f, void* buf, int size);
extern "C" unsigned int func_001053C8(const void* data, int size);
extern "C" void* func_00122CF8(int size);
extern "C" const char* func_001E54B8(const char* name, int a);
extern "C" void func_001E6AC8(Prm_284B0* s, Prm_284B0* sub);
extern "C" void func_001E6C28(Prm_284B0* s, const char* name);
extern "C" void func_001E7138(Prm_284B0* s, const char* name, const char* v);
extern "C" void func_001E7268(Prm_284B0* s, const char* name, int v);
extern "C" void func_001E7360(Prm_284B0* s, const char* name, unsigned int v);
extern "C" void func_001E73C8(Prm_284B0* s, const char* name, unsigned int v);
extern "C" void func_001E7788(Prm_284B0* s, const char* name, void* arr);
extern "C" bool func_001E84E8(Prm_284B0* s, const char* name, unsigned int* out, int required);
extern "C" void* func_001E8DD0(void* mem);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void func_001E9170(void* arr, int i, Prm_284B0* s);
extern "C" void func_001E9D70(Prm_284B0* s, const void* data);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" unsigned int func_00224400(char c);
extern "C" int func_00225D90(unsigned int type, int size);
extern "C" int func_00225EC0(unsigned int type);
extern "C" bool func_00226B78(Prm_284B0* a, Prm_284B0* b);
extern "C" void func_00229058();
extern "C" int func_00229068();
extern "C" void func_00229088();
extern "C" void func_002290A8();
extern "C" void func_002290B8();
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_00331BB8(const char* s);

struct Script_284B0 {
    char pad0[0x18];
    Prm_284B0* m_params;
};

static inline void MarkDamaged_284B0(Prm_284B0* s, const char* name)
{
    func_001E7360(s, 0, func_001F0D78(D_0038FA20));
    func_001E7138(s, D_003722E0, func_001E54B8(name, 0));
}

bool ScriptGetMemCardDirectoryListing_284B0(Prm_284B0* params, Script_284B0* script)
{
    unsigned int fileType;

    func_001E6C28(script->m_params, D_00372388);
    func_001E6C28(script->m_params, D_003723A0);
    func_001E6C28(script->m_params, D_003723B8);
    fileType = 0;
    func_001E84E8(params, D_003723D0, &fileType, 0);

    void* card = func_00112FB8(D_00388EFC, 0, 0);
    if (!card)
        return true;

    ListHead_284B0 files;
    Prm_284B0* entries[75];
    char path[0x70];
    func_00113430(card, D_0038FA38, &files);
    int resume = 0;
    func_00229058();
    if (func_00229068()) {
        func_00229088();
        resume = 1;
    } else {
        func_002290A8();
    }

    int count = 0;
    const char* prefix = (const char*)func_00106810();
    int numFiles = 0;
    int prefixLen = func_00331BB8(prefix);
    for (ListNode_284B0* n = files.First(); n; n = n->m_next->Valid())
        numFiles++;

    int total = 0;
    for (int i = 0; i < numFiles; i++) {
        ListNode_284B0* n = files.First();
        int k = i;
        while (n) {
            if (k-- == 0)
                break;
            n = n->m_next->Valid();
        }
        CardFile_284B0* file = n->m_data;

        int platform = D_00388814;
        bool ours = true;
        if (platform != 4) {
            for (int j = 0; j < prefixLen; j++) {
                if (file->m_name[j] != prefix[j]) {
                    ours = false;
                    break;
                }
            }
        }
        if (!ours)
            continue;
        total++;

        unsigned int type = 0;
        if (platform == 1 || platform == 2 || platform == 3 || platform == 5)
            type = func_00224400(file->m_name[prefixLen + 7]);
        if (!(fileType == 0 && type != 0) && type != fileType)
            continue;
        if (count >= 75)
            continue;

        Prm_284B0* entry = new Prm_284B0;
        func_001E73C8(entry, D_003721E8, type);
        func_001E7268(entry, D_0038FA40, count);
        func_001E7268(entry, D_0038FA48, file->m_year);
        func_001E7268(entry, D_0038FA50, file->m_month);
        func_001E7268(entry, D_0038FA58, file->m_day);
        func_001E7268(entry, D_0038FA60, file->m_hour);
        func_001E7268(entry, D_0038FA68, file->m_min);
        func_001E7268(entry, D_0038FA70, file->m_sec);
        if (D_00388814 == 5)
            func_003331D0(path, D_0038FA78, file->m_name);
        else
            func_003331D0(path, D_0038F9E8, file->m_name, file->m_name);
        func_001E7138(entry, D_003723E0, path);

        File_284B0* f = func_00113380(card, path, 1, 0);
        if (f) {
            func_001139D8(f, 0, 0);
            SaveHeader_284B0* hdr = &D_003F5910;
            func_00113B10(f, hdr, 0x78);
            bool corrupt = true;
            if (hdr->m_size <= 100)
                corrupt = func_001053C8(hdr->m_data, hdr->m_size) != hdr->m_checksum;
            func_001E7268(entry, D_00372228, func_00225D90(type, func_001139D8(f, 0, 2)));
            if (corrupt || func_00225EC0(type) != hdr->m_version) {
                MarkDamaged_284B0(entry, D_00388814 == 5 ? D_003723F8 : D_00372408);
            } else {
                Prm_284B0* data = new Prm_284B0;
                func_001E9D70(data, hdr->m_data);
                func_001E6AC8(entry, data);
                delete data;
            }
            func_00113988(f);
            delete f;
        } else {
            MarkDamaged_284B0(entry, D_00372408);
        }
        entries[count++] = entry;
    }

    if (resume) {
        func_002290A8();
        func_002290B8();
    }

    ListNode_284B0* n = files.First();
    while (n) {
        ListNode_284B0* next = n->m_next->Valid();
        delete n;
        n = next;
    }

    func_001E7268(script->m_params, D_003723B8, total);
    if (total >= 75)
        func_001E7360(script->m_params, 0, 0x4EEC27B5);

    if (count) {
        bool swapped;
        do {
            swapped = false;
            for (int j = 0; j < count - 1; j++) {
                if (func_00226B78(entries[j + 1], entries[j])) {
                    Prm_284B0* t = entries[j];
                    entries[j] = entries[j + 1];
                    entries[j + 1] = t;
                    swapped = true;
                }
            }
        } while (swapped);

        void* arr = func_001E8DD0(func_00122CF8(0x10));
        func_001E8E98(arr, count, 10);
        for (int j = 0; j < count; j++)
            func_001E9170(arr, j, entries[j]);
        func_001E7788(script->m_params, D_00372388, arr);
    }
    return true;
}
