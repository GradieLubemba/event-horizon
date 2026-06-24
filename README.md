# Event Horizon

A collaborative calendar and task-management web app for small groups — student project teams,
clubs, and small organizations. Members share a group calendar, RSVP to events, create and openly
**claim** group tasks, keep **private** personal tasks, invite each other to groups, and publish
their **busy** windows so the group can find times that work.

> **Status:** in active development (MVP). See [`PLAN.md`](PLAN.md) for the phased build plan.

**Team Singularity:** Quinn Steadman · Grant Bassler · Gradie Lubemba

## ▶ Run it on your computer

Install **[Docker Desktop](https://www.docker.com/products/docker-desktop/)** (the only prerequisite)
and open it, then:

- **Easiest — just double-click:** `start.command` (Mac) or `start.bat` (Windows). It builds and
  starts everything, loads the demo data, opens the app, and prints a link other people on your
  network can use to join. Stop with `stop.command` / `stop.bat`.
- **Or from a terminal:** `docker compose up --build`

Either way, open **http://localhost:5173** and log in with `grant@demo.test` / `EventHorizon1` (demo
data is pre-loaded).

**Full step-by-step, demo logins, sharing on your network, and troubleshooting: [`RUN.md`](RUN.md).**

## Architecture

Three-tier web application:

- **Frontend** — React 19 + TypeScript (Vite 8), FullCalendar v6, Tailwind CSS v4.
- **Backend** — Java 21 (Temurin) + Spring Boot 3.5 (Web, Security, Validation, Data JPA), Flyway, HikariCP.
- **Database** — MySQL 8.4.

The SPA talks to the Spring Boot REST API over JSON/HTTPS; the API persists to MySQL via JPA with
Flyway-managed migrations.

## Repository layout

| Path | Contents |
| --- | --- |
| [`PLAN.md`](PLAN.md) | Phased PR build plan + locked decisions |
| [`docs/`](docs/) | Design doc, functional spec, ADRs, diagrams, mockups |
| [`docs/decisions/`](docs/decisions/) | Architecture Decision Records |
| [`docs/backlog.md`](docs/backlog.md) | Intentionally deferred features |
| `backend/` | Spring Boot API *(added in PR 0.2)* |
| `frontend/` | React SPA *(added in PR 0.3)* |
| `docker-compose.yml` | Full local stack *(added in PR 0.4)* |

## Quickstart

The one-command Docker flow (above, and in **[`RUN.md`](RUN.md)**) is all most people need — it
requires only Docker and ships seeded demo data. Start it, then:

```bash
docker compose up             # start everything (add --build after pulling changes)
docker compose down           # stop everything when you're done
```

| What | URL |
| --- | --- |
| Frontend (SPA) | http://localhost:5173 |
| API health | http://localhost:8080/api/health |

`make` shortcuts: `make up` / `make down` / `make logs` / `make smoke` / `make reset` (wipe the DB volume).

**Developing against the code directly** (running the API or SPA outside Docker, with hot reload)?
Install the toolchain per [`docs/setup.md`](docs/setup.md).

## Workflow

Feature-branch + peer-review: branch off `main`, open a PR, ≥1 review before merge. Conventional
commits. Tests written with the code. Conventions live in [`PLAN.md`](PLAN.md).

**CI:** GitHub Actions runs on every PR — a **backend** job (Maven build + unit + Testcontainers
integration tests on Java 21) and a **frontend** job (lint + unit tests + build on Node 24). A
separate **E2E** job (Playwright against the full Docker stack, see [`e2e/`](e2e)) runs on PRs and on
demand. Enable branch protection on `main` to require both checks **and** ≥1 review before merging.

## Documentation

Full index: **[`docs/README.md`](docs/README.md)**. Highlights:

- [`docs/design_doc.md`](docs/design_doc.md) — authoritative technical design
- [`docs/functional_spec.md`](docs/functional_spec.md) — functional requirements (v0.2)
- [`docs/roadmap.md`](docs/roadmap.md) — milestone roadmap · [`PLAN.md`](PLAN.md) — per-PR plan
- [`docs/ui-ux-guidelines.md`](docs/ui-ux-guidelines.md) — UI/UX standardization
- [`docs/decisions/`](docs/decisions/) — ADRs
