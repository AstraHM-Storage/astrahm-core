# AstraHM Storage Engine

![Build](https://img.shields.io/badge/build-passing-brightgreen)
![Language](https://img.shields.io/badge/language-C-blue)
![Platform](https://img.shields.io/badge/platform-Linux-lightgrey)
![License](https://img.shields.io/badge/license-MIT-green)
![Status](https://img.shields.io/badge/status-active-success)

AstraHM is a **software-defined storage engine** designed to deliver reliability, performance, and scalability using modern storage architecture principles.

It simulates RAID-style redundancy, disk management, parallel IO, and recovery workflows — forming the foundation for a future distributed storage platform.

---

## ✨ Key Features

### 🔐 Reliability & Data Protection
- RAID-style parity generation
- Disk failure simulation & recovery
- Data reconstruction & rebuild workflow

### 💾 Storage Engine Core
- Stripe distribution engine
- Disk abstraction layer
- Centralized disk manager

### ⚡ Performance & Concurrency
- Parallel disk IO simulation
- Threaded concurrent writes
- Fault-tolerant IO under failure

### 🧠 Storage Intelligence
- Metadata block mapping
- Logging & observability

---

## 🧱 Architecture Overview

AstraHM uses a layered storage architecture inspired by enterprise storage systems.











## License#######################################################

This project is licensed under the MIT License.

# astrahm-core
Hybrid Mesh Storage Fabric core engine for HPC, AI, and enterprise infrastructure.
# AstraHM Core

AstraHM is a high-availability hybrid mesh storage fabric designed for HPC, AI, and enterprise infrastructure.

## Key Objectives

- Software-defined storage engine
- RAID & erasure coding
- Lustre-ready architecture
- RDMA & high-speed networking
- Cloud-scale distributed design
## Current Features

- RAID6 parity & recovery simulation
- Stripe distribution engine
- Disk abstraction layer
- Centralized disk manager
- Disk rebuild workflow
- Threaded parallel IO simulation
- Metadata mapping service

## 🧱 1️⃣ System Architecture Overview

##  AstraHM Storage Engine — Base architecture


                    +----------------------+
                    |   Application Layer  |
                    |  (future clients)   |
                    +----------+----------+
                               |
                               v
                    +----------------------+
                    |   Engine Controller  |
                    |   main() workflow   |
                    +----------+----------+
                               |
      ---------------------------------------------------------
      |                       |                              |
      v                       v                              v

+-------------+     +------------------+        +------------------+
|   Logging   |     |  Metadata Layer  |        |  Monitoring (*)  |
|  subsystem  |     | block placement  |        |   (future)       |
+-------------+     +------------------+        +------------------+

                               |
                               v

                    +----------------------+
                    |   IO / Storage Core  |
                    +----------+-----------+
                               |
      ---------------------------------------------------------
      |                       |                              |
      v                       v                              v

+----------------+   +--------------------+     +---------------------+
| RAID Engine    |   | Stripe Writer      |     | Rebuild Engine      |
| parity & recov |   | data distribution  |     | disk recovery       |
+----------------+   +--------------------+     +---------------------+

                               |
                               v

                    +----------------------+
                    |  Async / IO Engine  |
                    |  (next step)        |
                    +----------+----------+
                               |
      ---------------------------------------------------------
      |                       |                              |
      v                       v                              v

+----------------+   +--------------------+     +--------------------+
| Parallel IO    |   | Threaded IO        |     | IO Queue (*)       |
| simulation     |   | concurrent writes  |     | (future)           |
+----------------+   +--------------------+     +--------------------+

                               |
                               v

                    +----------------------+
                    |   Disk Manager       |
                    | centralized control  |
                    +----------+-----------+
                               |
       --------------------------------------------------------
       |            |            |            |               |
       v            v            v            v               v

   +--------+   +--------+   +--------+   +--------+   +--------+
   | Disk 1 |   | Disk 2 |   | Disk 3 |   | Disk 4 |   | Disk 5 |
   | data   |   | data   |   | data   |   |  P     |   |  Q     |
   +--------+   +--------+   +--------+   +--------+   +--------+

                    (Replacement disks added during rebuild)


## ⚡ Where Async IO Will Fit

    Async IO sits between:
    Storage Core
     ↓
    Async IO Engine
         ↓
    Disk manager

    It manages request queues and dispatch.

###     Data Flow Diagram ###
        

        Client / Application
                |
                v
        Engine Controller (main)
                |
                v
            Stripe Writer
                |
                v
    RAID Engine → generates parity
                |
                v
    IO Layer (parallel / threaded)
                |
0                v
            Disk Manager
                |
                v
            Physical Disks

###     🧱 3️⃣ RAID Stripe Layout Visualization

            Example Stripe (RAID-6 style)

            +---------+---------+---------+---------+---------+
            | Disk 1  | Disk 2  | Disk 3  | Disk 4  | Disk 5  |
            +---------+---------+---------+---------+---------+
            |  D1     |   D2    |   D3    |   P     |   Q     |
            +---------+---------+---------+---------+---------+


            🧠 Meaning

D1–D3 → data blocks

P → XOR parity

Q → Reed-Solomon parity (future real math)

###   🌐 7️⃣ Future Cluster Architecture (Preview)

              +------------------+
              |   Cluster Node A |
              |   AstraHM Core   |
              +--------+---------+
                       |
                       | replication
                       |
+------------------+   |   +------------------+
|   Cluster Node B |<--+-->|   Cluster Node C |
|   AstraHM Core   |       |   AstraHM Core   |
+------------------+       +------------------+

# Astrahm Storage Engine

![Build](https://img.shields.io/badge/build-passing-brightgreen)
![Language](https://img.shields.io/badge/language-C-blue)
![Platform](https://img.shields.io/badge/platform-Linux-lightgrey)
![License](https://img.shields.io/badge/license-MIT-green)
![Status](https://img.shields.io/badge/status-active-success)

Astrahm is a **software-defined storage engine** designed to provide reliability, performance, and scalability using modern storage architecture principles.

It simulates RAID-style redundancy, disk management, parallel IO, and recovery workflows — forming the foundation for a future distributed storage platform.

---

## ✨ Key Features

### 🔐 Reliability & Data Protection
- RAID-style parity generation
- Disk failure simulation & recovery
- Data reconstruction & rebuild workflow

### 💾 Storage Engine Core
- Stripe distribution engine
- Disk abstraction layer
- Centralized disk manager

### ⚡ Performance & Concurrency
- Parallel disk IO simulation
- Threaded concurrent writes
- Fault-tolerant IO under failure

### 🧠 Storage Intelligence
- Metadata block mapping
- Logging & observability

---

## 🧱 Architecture Overview

Astrahm uses a layered storage architecture inspired by enterprise storage systems.


This modular design ensures scalability, resilience, and maintainability.

---

## 🔄 Data Flow



---

## 🧱 RAID Stripe Layout

- **D1–D3** → data blocks  
- **P** → XOR parity  
- **Q** → Reed-Solomon parity (future)

---

## 💥 Failure & Rebuild Workflow




## Status

🚧 Early development
