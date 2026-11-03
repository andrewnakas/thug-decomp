# Provenance

This project only accepts work that anyone could reproduce from a legally owned copy of the game and lawful tools.
Every pull request carries the provenance checklist from `.github/pull_request_template.md`, and Steward will not
merge a PR until every box is ticked.

## The leaked THUG source is off limits

Neversoft source code for Tony Hawk's Underground has leaked and is publicly mirrored (for example the `thug1src`
trees and forks of them such as "RetailGameSourceCode/TonyHawksUnderground"). **Do not open, read, search, copy
from or paraphrase it, or any other leaked Neversoft/Activision material, while working on this project.** That
includes class, function and variable names, file names, struct layouts and comments taken from it. A PR that
was influenced by it is rejected and its functions are re-done from scratch by someone else.

Names in this repo come only from the binary itself (assert strings such as `/code/sk/objects/skater.cpp`, other
strings, behaviour, Sony SDK and open-source library signatures) or from your own judgement.

## What the boxes mean

- **Own work.** You wrote it, or an AI agent you run wrote it under your direction, or you have permission from
  whoever did.
- **No leaked material.** Nothing from leaked or confidential Neversoft or Activision source code (see above),
  debug symbols, linker maps, internal builds or internal documents.
- **No game data.** No disc images or executable bytes, no game assets, no proprietary Sony SDK files. The repo
  only holds our C++, tools and configuration; the game is read from your own disc at build time.
- **Lawful decompilation.** You worked from a copy of the game you legally own, with tools you are legally allowed
  to use (the open-source tools in this repo, splat, spimdisasm, m2c, objdiff, decomp-permuter, your own scripts).
- **Sources listed.** Anything you relied on beyond the repo's own tools is named in the PR.

## Humans and AI agents

Tick exactly one "who made this" box.

AI agents may prepare and submit PRs. An agent has to tick the boxes itself **on every PR**, after checking each
statement against that PR's actual changes, and must also tick the agent acknowledgement. The acknowledgement
says that the human who runs the agent is responsible for the contribution. An earlier PR's ticks never carry
over.

If you are unsure about any box, leave it unticked and ask in the PR.
