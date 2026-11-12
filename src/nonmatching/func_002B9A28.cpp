/* cflags: -fno-gcse */
/* fuzzy: 62.1 */
/* nonmatch func_002B9A28 (0x9EC): fresh draft from the asm. Builds restart nodes (and CTF flag/base nodes) for the 18 restart slots. */
extern char D_00392650[]; /* "angles" */
extern char D_00392658[]; /* "name" */
extern char D_00392660[]; /* "class" */
extern char D_00392678[]; /* "type" */
extern char D_00392680[]; /* "restart" */
extern char D_00392688[]; /* "model" */
extern char D_00392690[];
extern char D_00392698[];
extern char D_003926A0[];
extern char D_003926A8[];
extern char D_003926B0[];
extern char D_003926B8[];
extern char D_003926C0[];
extern char D_003926C8[];
extern char D_003926D0[];
extern char D_0037A118[];
extern char D_0037A128[];
extern char D_0037A168[];
extern char D_0037A178[];
extern char D_0037A188[];
extern char D_0037A198[];
extern char D_0037A1A8[];
extern char D_0037A1C0[];
extern char D_0037A1D8[];
extern char D_0037A1F0[];
extern char D_0037A208[];
extern char D_0037A218[];
extern char D_0037A230[];
extern char D_0037A248[];
extern char D_0037A258[];
extern char D_0037A268[];
extern char D_0037A290[];
extern char D_0037A2B0[];
extern char D_0037A2C0[];
extern char D_0037A2D0[];
extern char D_0037A2E0[];
extern char D_0037A2F0[];
extern char D_0037A300[];
extern char D_0037A310[];
extern char D_0037A320[];
extern char D_0037A330[];
extern char D_0037A340[];

extern "C" void* func_00122CF8(int size);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001E7A30(void* s, int name, int type, char* v);
extern "C" void func_001E7A68(void* s, int name, int type, int value);
extern "C" void func_001E7AF8(void* s, int name, float x, float y, float z);
extern "C" void func_001E7B38(void* s, int name, void* arr);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8DE8(void* arr, int flags);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void func_001E90F8(void* self, int index, int value);
extern "C" void* func_001E9378(void* a, int i);
extern "C" int func_001F0D78(char* s);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);

struct Restart_002B9A28 {
    float x, y, z, w;
    int dir;
    char pad14[0x1C - 0x14];
    int type;
    char pad20[0x30 - 0x20];
};

struct Obj_002B9A28 {
    char pad[0xB0];
    Restart_002B9A28 m_restarts[18];
    void AddNodes(void* nodes, int* index);
};

void Obj_002B9A28::AddNodes(void* nodes, int* index)
{
    char nodeName[0x100];
    char flagName[0x100];
    char modelName[0x100];
    char scriptName[0x100];
    int crcAngles = func_001F0D78(D_00392650);
    int crcName = func_001F0D78(D_00392658);
    int crcClass = func_001F0D78(D_00392660);
    int crcType = func_001F0D78(D_00392678);
    int crcRestart = func_001F0D78(D_00392680);
    int crcGeneric = func_001F0D78(D_0037A168);
    int crcCreated = func_001F0D78(D_0037A118);
    int crcRestartName = func_001F0D78(D_0037A178);
    int crcRestartTypes = func_001F0D78(D_0037A188);
    int crcModel = func_001F0D78(D_00392688);
    int crcTrigger = func_001F0D78(D_0037A128);
    int id = 0x5B8D81;

    for (int i = 0; i < 18; i++) {
        int type = m_restarts[i].type;
        if (!type)
            continue;
        int count = (type == 1 || type == 3) ? 2 : 1;
        for (int j = 0; j < count; j++) {
            int name = id++;
            int rtype = 0;
            if (m_restarts[i].type == 1)
                rtype = func_001F0D78(D_00392690);
            if (m_restarts[i].type == 3)
                rtype = func_001F0D78(D_00392698);
            if (m_restarts[i].type == 2 || j == 1)
                rtype = func_001F0D78(D_0037A198);
            if (m_restarts[i].type == 4)
                rtype = func_001F0D78(D_003926A0);
            if ((unsigned int)(m_restarts[i].type - 5) < 4) {
                rtype = func_001F0D78(D_003926A8);
                switch (m_restarts[i].type) {
                case 5:
                    name = func_001F0D78(D_0037A1A8);
                    break;
                case 6:
                    name = func_001F0D78(D_0037A1C0);
                    break;
                case 7:
                    name = func_001F0D78(D_0037A1D8);
                    break;
                case 8:
                    name = func_001F0D78(D_0037A1F0);
                    break;
                }
            }
            if (rtype) {
                void* node = func_001E9378(nodes, *index);
                if (m_restarts[i].type == 4) {
                    func_001E7AF8(node, 0x7F261953, m_restarts[i].x, m_restarts[i].y + 50.0f, m_restarts[i].z);
                    func_001E7A68(node, crcClass, 0xD, crcGeneric);
                } else {
                    func_001E7AF8(node, 0x7F261953, m_restarts[i].x, m_restarts[i].y + 50.0f, m_restarts[i].z);
                    func_001E7A68(node, crcClass, 0xD, crcRestart);
                }
                func_001E7AF8(node, crcAngles, 0.0f, ((float)m_restarts[i].dir + 2.0f) * 1.5707964f, 0.0f);
                func_001E7A68(node, crcName, 0xD, name);
                func_001E7A68(node, crcType, 0xD, rtype);
                func_001E7A68(node, 0, 0xD, crcCreated);
                if (m_restarts[i].type != 4) {
                    char* label = D_0037A208;
                    if (j == 0) {
                        int t = m_restarts[i].type;
                        if (t == 1)
                            label = D_0037A218;
                        else if (t == 2)
                            label = D_0037A230;
                        else if (t == 3)
                            label = D_0037A248;
                        else if (t >= 5 && t <= 8)
                            label = D_0037A258;
                    }
                    func_001E7A30(node, crcRestartName, 3, label);
                    void* types = func_001E8DD0(func_00122CF8(0x10));
                    func_001E8E98(types, 1, 0xD);
                    func_001E90F8(types, 0, rtype);
                    func_001E7B38(node, crcRestartTypes, types);
                    if (types)
                        func_001E8DE8(types, 3);
                }
                *index += 1;
            }
            char* color = 0;
            if ((unsigned int)(m_restarts[i].type - 5) < 4) {
                void* node = func_001E9378(nodes, *index);
                int t = m_restarts[i].type;
                if (t == 5)
                    color = D_003926B0;
                if (t == 6)
                    color = D_003926B8;
                if (t == 7)
                    color = D_003926C0;
                if (t == 8)
                    color = D_003926C8;
                func_003331D0(flagName, D_003926D0, color);
                func_003331D0(modelName, D_0037A268, color, color);
                func_003331D0(scriptName, D_0037A290, color);
                func_003331D0(nodeName, D_0037A2B0, color);
                func_001E7AF8(node, 0x7F261953, m_restarts[i].x, m_restarts[i].y, m_restarts[i].z);
                func_001E7AF8(node, crcAngles, 0.0f, ((float)m_restarts[i].dir + 2.0f) * 1.5707964f, 0.0f);
                func_001E7A68(node, crcName, 0xD, func_001F0D78(nodeName));
                func_001E7A68(node, crcClass, 0xD, func_001F0D78(D_0037A2C0));
                func_001E7A68(node, crcType, 0xD, func_001F0D78(flagName));
                func_001E7A30(node, crcModel, 3, modelName);
                func_001E7A68(node, crcTrigger, 0xD, func_001F0D78(scriptName));
                func_001E7268(node, D_0037A2D0, *index);
                func_001E7268(node, D_0037A2E0, 0);
                func_001E7268(node, D_0037A2F0, 800);
                func_001E7268(node, D_0037A300, 801);
                *index += 1;

                node = func_001E9378(nodes, *index);
                func_003331D0(nodeName, D_0037A310, color);
                func_001E7AF8(node, 0x7F261953, m_restarts[i].x, m_restarts[i].y, m_restarts[i].z);
                func_001E7AF8(node, crcAngles, 0.0f, ((float)m_restarts[i].dir + 2.0f) * 1.5707964f, 0.0f);
                func_001E7A68(node, crcName, 0xD, func_001F0D78(nodeName));
                func_001E7A68(node, crcClass, 0xD, func_001F0D78(D_0037A2C0));
                func_001E7A68(node, crcType, 0xD, func_001F0D78(flagName));
                func_001E7A30(node, crcModel, 3, modelName);
                func_001E7A68(node, crcTrigger, 0xD, func_001F0D78(scriptName));
                func_001E7268(node, D_0037A2D0, *index);
                func_001E7268(node, D_0037A2E0, 0);
                func_001E7268(node, D_0037A2F0, 800);
                func_001E7268(node, D_0037A300, 801);
                *index += 1;

                node = func_001E9378(nodes, *index);
                func_003331D0(nodeName, D_0037A320, color);
                func_003331D0(flagName, D_0037A330, color);
                func_003331D0(modelName, D_0037A340, color, color);
                func_001E7AF8(node, 0x7F261953, m_restarts[i].x, m_restarts[i].y, m_restarts[i].z);
                func_001E7AF8(node, crcAngles, 0.0f, ((float)m_restarts[i].dir + 2.0f) * 1.5707964f, 0.0f);
                func_001E7A68(node, crcName, 0xD, func_001F0D78(nodeName));
                func_001E7A68(node, crcClass, 0xD, func_001F0D78(D_0037A2C0));
                func_001E7A68(node, crcType, 0xD, func_001F0D78(flagName));
                func_001E7A30(node, crcModel, 3, modelName);
                func_001E7268(node, D_0037A2D0, *index);
                func_001E7268(node, D_0037A2E0, 0);
                func_001E7268(node, D_0037A2F0, 800);
                func_001E7268(node, D_0037A300, 801);
                *index += 1;
            }
        }
    }
}
