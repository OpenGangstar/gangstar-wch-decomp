SECTIONS
{
    .application_singleton 0x002d528c : { *application-helpers.o(.text._ZN11Application11GetInstanceEv) }
    .application_singleton_cleanup 0x002d5d88 : { *application-helpers.o(.text.__tcf_1) }
    .application_singleton_guard 0x004b684c (NOLOAD) : { *application-helpers.o(.bss._ZGVZN11Application11GetInstanceEvE3app) }
    .application_singleton_storage 0x004b6850 (NOLOAD) : { *application-helpers.o(.bss._ZZN11Application11GetInstanceEvE3app) }
}
