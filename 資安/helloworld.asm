
helloworld:     file format elf64-littleaarch64

Disassembly of section .init:

00000000000005d0 <_init>:
     5d0: d503233f      paciasp
     5d4: a9bf7bfd      stp     x29, x30, [sp, #-0x10]!
     5d8: 910003fd      mov     x29, sp
     5dc: 94000036      bl      0x6b4 <call_weak_fn>
     5e0: a8c17bfd      ldp     x29, x30, [sp], #0x10
     5e4: d50323bf      autiasp
     5e8: d65f03c0      ret

Disassembly of section .plt:

00000000000005f0 <.plt>:
     5f0: a9bf7bf0      stp     x16, x30, [sp, #-0x10]!
     5f4: f00000f0      adrp    x16, 0x1f000 <puts@GLIBC_2.17+0x1f000>
     5f8: f947d211      ldr     x17, [x16, #0xfa0]
     5fc: 913e8210      add     x16, x16, #0xfa0
     600: d61f0220      br      x17
     604: d503201f      nop
     608: d503201f      nop
     60c: d503201f      nop

0000000000000610 <__libc_start_main@plt>:
     610: f00000f0      adrp    x16, 0x1f000 <puts@GLIBC_2.17+0x1f000>
     614: f947d611      ldr     x17, [x16, #0xfa8]
     618: 913ea210      add     x16, x16, #0xfa8
     61c: d61f0220      br      x17

0000000000000620 <__cxa_finalize@plt>:
     620: f00000f0      adrp    x16, 0x1f000 <puts@GLIBC_2.17+0x1f000>
     624: f947da11      ldr     x17, [x16, #0xfb0]
     628: 913ec210      add     x16, x16, #0xfb0
     62c: d61f0220      br      x17

0000000000000630 <__gmon_start__@plt>:
     630: f00000f0      adrp    x16, 0x1f000 <puts@GLIBC_2.17+0x1f000>
     634: f947de11      ldr     x17, [x16, #0xfb8]
     638: 913ee210      add     x16, x16, #0xfb8
     63c: d61f0220      br      x17

0000000000000640 <abort@plt>:
     640: f00000f0      adrp    x16, 0x1f000 <puts@GLIBC_2.17+0x1f000>
     644: f947e211      ldr     x17, [x16, #0xfc0]
     648: 913f0210      add     x16, x16, #0xfc0
     64c: d61f0220      br      x17

0000000000000650 <puts@plt>:
     650: f00000f0      adrp    x16, 0x1f000 <puts@GLIBC_2.17+0x1f000>
     654: f947e611      ldr     x17, [x16, #0xfc8]
     658: 913f2210      add     x16, x16, #0xfc8
     65c: d61f0220      br      x17

Disassembly of section .text:

0000000000000680 <_start>:
     680: d503245f      bti     c
     684: d280001d      mov     x29, #0x0               // =0
     688: d280001e      mov     x30, #0x0               // =0
     68c: aa0003e5      mov     x5, x0
     690: f94003e1      ldr     x1, [sp]
     694: 910023e2      add     x2, sp, #0x8
     698: 910003e6      mov     x6, sp
     69c: f00000e0      adrp    x0, 0x1f000 <puts@GLIBC_2.17+0x1f000>
     6a0: f947f800      ldr     x0, [x0, #0xff0]
     6a4: d2800003      mov     x3, #0x0                // =0
     6a8: d2800004      mov     x4, #0x0                // =0
     6ac: 97ffffd9      bl      0x610 <__libc_start_main@plt>
     6b0: 97ffffe4      bl      0x640 <abort@plt>

00000000000006b4 <call_weak_fn>:
     6b4: f00000e0      adrp    x0, 0x1f000 <puts@GLIBC_2.17+0x1f000>
     6b8: f947f400      ldr     x0, [x0, #0xfe8]
     6bc: b4000040      cbz     x0, 0x6c4 <call_weak_fn+0x10>
     6c0: 17ffffdc      b       0x630 <__gmon_start__@plt>
     6c4: d65f03c0      ret
     6c8: d503201f      nop
     6cc: d503201f      nop
     6d0: d503201f      nop
     6d4: d503201f      nop
     6d8: d503201f      nop
     6dc: d503201f      nop

00000000000006e0 <deregister_tm_clones>:
     6e0: 90000100      adrp    x0, 0x20000 <data_start>
     6e4: 91004000      add     x0, x0, #0x10
     6e8: 90000101      adrp    x1, 0x20000 <data_start>
     6ec: 91004021      add     x1, x1, #0x10
     6f0: eb00003f      cmp     x1, x0
     6f4: 540000c0      b.eq    0x70c <deregister_tm_clones+0x2c>
     6f8: f00000e1      adrp    x1, 0x1f000 <puts@GLIBC_2.17+0x1f000>
     6fc: f947ec21      ldr     x1, [x1, #0xfd8]
     700: b4000061      cbz     x1, 0x70c <deregister_tm_clones+0x2c>
     704: aa0103f0      mov     x16, x1
     708: d61f0200      br      x16
     70c: d65f03c0      ret

0000000000000710 <register_tm_clones>:
     710: 90000100      adrp    x0, 0x20000 <data_start>
     714: 91004000      add     x0, x0, #0x10
     718: 90000101      adrp    x1, 0x20000 <data_start>
     71c: 91004021      add     x1, x1, #0x10
     720: cb000021      sub     x1, x1, x0
     724: d37ffc22      lsr     x2, x1, #63
     728: 8b810c41      add     x1, x2, x1, asr #3
     72c: 9341fc21      asr     x1, x1, #1
     730: b40000c1      cbz     x1, 0x748 <register_tm_clones+0x38>
     734: f00000e2      adrp    x2, 0x1f000 <puts@GLIBC_2.17+0x1f000>
     738: f947fc42      ldr     x2, [x2, #0xff8]
     73c: b4000062      cbz     x2, 0x748 <register_tm_clones+0x38>
     740: aa0203f0      mov     x16, x2
     744: d61f0200      br      x16
     748: d65f03c0      ret

000000000000074c <__do_global_dtors_aux>:
     74c: d503233f      paciasp
     750: a9be7bfd      stp     x29, x30, [sp, #-0x20]!
     754: 910003fd      mov     x29, sp
     758: f9000bf3      str     x19, [sp, #0x10]
     75c: 90000113      adrp    x19, 0x20000 <data_start>
     760: 39404260      ldrb    w0, [x19, #0x10]
     764: 37000140      tbnz    w0, #0x0, 0x78c <__do_global_dtors_aux+0x40>
     768: f00000e0      adrp    x0, 0x1f000 <puts@GLIBC_2.17+0x1f000>
     76c: f947f000      ldr     x0, [x0, #0xfe0]
     770: b4000080      cbz     x0, 0x780 <__do_global_dtors_aux+0x34>
     774: 90000100      adrp    x0, 0x20000 <data_start>
     778: f9400400      ldr     x0, [x0, #0x8]
     77c: 97ffffa9      bl      0x620 <__cxa_finalize@plt>
     780: 97ffffd8      bl      0x6e0 <deregister_tm_clones>
     784: 52800020      mov     w0, #0x1                // =1
     788: 39004260      strb    w0, [x19, #0x10]
     78c: f9400bf3      ldr     x19, [sp, #0x10]
     790: a8c27bfd      ldp     x29, x30, [sp], #0x20
     794: d50323bf      autiasp
     798: d65f03c0      ret
     79c: d503201f      nop

00000000000007a0 <frame_dummy>:
     7a0: d503245f      bti     c
     7a4: 17ffffdb      b       0x710 <register_tm_clones>

00000000000007a8 <main>:
     7a8: a9bf7bfd      stp     x29, x30, [sp, #-0x10]!
     7ac: 910003fd      mov     x29, sp
     7b0: 90000000      adrp    x0, 0x0 <puts@GLIBC_2.17>
     7b4: 911fa000      add     x0, x0, #0x7e8
     7b8: 97ffffa6      bl      0x650 <puts@plt>
     7bc: 52800000      mov     w0, #0x0                // =0
     7c0: a8c17bfd      ldp     x29, x30, [sp], #0x10
     7c4: d65f03c0      ret

Disassembly of section .fini:

00000000000007c8 <_fini>:
     7c8: d503233f      paciasp
     7cc: a9bf7bfd      stp     x29, x30, [sp, #-0x10]!
     7d0: 910003fd      mov     x29, sp
     7d4: a8c17bfd      ldp     x29, x30, [sp], #0x10
     7d8: d50323bf      autiasp
     7dc: d65f03c0      ret

