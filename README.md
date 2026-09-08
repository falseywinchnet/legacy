# Legacy — Software Forward Port Effort

This repository is a **legacy software forward port effort**: a home for bringing older software forward to current operating systems, hardware, toolchains, and dependency ecosystems while preserving its original purpose and behavior.

The goal is to make historically useful software buildable, runnable, and maintainable again, with clear records of what changed and why.

## Scope

- Recover and document original source, build instructions, dependencies, and platform assumptions.
- Update obsolete build systems, APIs, dependencies, and platform integrations for modern environments.
- Preserve meaningful functionality, data formats, and workflows wherever practical.
- Record compatibility changes, deliberate departures from original behavior, and remaining limitations.
- Establish reproducible builds and focused checks for each port as software is introduced.

## Porting principles

**Preserve provenance.** Identify the original project, author or maintainer, source location, version, and applicable license. Retain original copyright and attribution notices.

**Make changes traceable.** Keep imported source and subsequent porting changes distinguishable in version history. Explain why compatibility changes are necessary.

**Respect original behavior.** Treat existing behavior and file formats as compatibility requirements where feasible. Document intentional changes and migration needs.

**Verify on stated targets.** Document the operating system, architecture, compiler or runtime, dependency versions, and checks used to establish that a port works. Distinguish verified support from planned support.

## Adding a forward port

Each software project added here should include:

1. Its original identity, source, version, and license information.
2. A description of what the software does and why it is being carried forward.
3. Its original environment and intended modern target environments.
4. Reproducible setup, build, and run instructions.
5. A record of porting changes, verification results, known issues, and remaining work.

The repository structure can grow around the needs of the software being ported. Project-specific instructions should live alongside the relevant source.

## Current status

This repository is at the initial setup stage. No legacy software has been imported or ported yet, and no build or platform support is currently claimed.

## Licensing

Legacy software added to this repository retains its applicable licensing and attribution requirements. Consult the license files and notices accompanying each project. This README does not grant a blanket license for future imports or contributions.
