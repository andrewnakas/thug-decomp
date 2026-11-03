# Lessons carried over (thps64, Thrasher) and found here

| Lesson | From | Here |
|---|---|---|
| Fix the toolchain before grinding functions | thps64 | compiler pinned from a discriminating function (sd vs sq $ra) before any matching |
| Always re-split from scratch | thps64 | tools/split.py wipes asm/; fresh.py re-splits when inputs change |
| Pin every object at its address | Thrasher | configure.py; a wrong size fails the link or the sha1 |
| Never mask relocations | thps64 | match.py resolves every relocated field to an address (literals: by value) |
| Check the permuter's pipeline against the gate's | thps64 | permute.py drift checks; it refuses C++ it cannot parse |
| decomp.dev closed its public leaderboard | 2026 | progress goes to bytematch.dev from a disc-free objdiff report |
| `gh pr edit` breaks | thps64 | use `gh api -X PATCH repos/.../pulls/N` |
| Old SN gas objects don't link with modern ld | here | cc.py fixes symtab sh_info and the ABI flag |
| GNU as rejects o32 register names under -mabi=eabi | here | splat asm is assembled with -mabi=o64 |
| VU0 macro ops are not encodable by GNU as | here | split.py emits them as .word |
