/* Generated by Makefile from ../dirent.c ../fetch_seccomp_fprog.c ../fetch_struct_flock.c ../ipc_msgctl.c ../ipc_shmctl.c ../print_mq_attr.c ../print_msgbuf.c ../print_sigevent.c ../print_time.c ../print_timex.c ../printrusage.c ../printsiginfo.c ../sigaltstack.c ../sysinfo.c ../times.c ../utime.c; do not edit. */
typedef struct {
 bool (*fetch_seccomp_fprog) (struct tcb *tcp, const long addr, void *p);
#define fetch_seccomp_fprog MPERS_PRINTER_NAME(fetch_seccomp_fprog)

 bool (*fetch_struct_flock) (struct tcb *tcp, const long addr, void *p);
#define fetch_struct_flock MPERS_PRINTER_NAME(fetch_struct_flock)

 bool (*fetch_struct_flock64) (struct tcb *tcp, const long addr, void *p);
#define fetch_struct_flock64 MPERS_PRINTER_NAME(fetch_struct_flock64)

 void (*printmqattr) (struct tcb *tcp, const long addr);
#define printmqattr MPERS_PRINTER_NAME(printmqattr)

 void (*tprint_msgbuf) (struct tcb *tcp, const long addr, const unsigned long count);
#define tprint_msgbuf MPERS_PRINTER_NAME(tprint_msgbuf)

 void (*print_sigevent) (struct tcb *tcp, const long addr);
#define print_sigevent MPERS_PRINTER_NAME(print_sigevent)

 void (*print_timespec) (struct tcb *tcp, const long addr);
#define print_timespec MPERS_PRINTER_NAME(print_timespec)

 const char * (*sprint_timespec) (struct tcb *tcp, const long addr);
#define sprint_timespec MPERS_PRINTER_NAME(sprint_timespec)

 void (*print_timespec_utime_pair) (struct tcb *tcp, const long addr);
#define print_timespec_utime_pair MPERS_PRINTER_NAME(print_timespec_utime_pair)

 void (*print_itimerspec) (struct tcb *tcp, const long addr);
#define print_itimerspec MPERS_PRINTER_NAME(print_itimerspec)

 void (*print_timeval) (struct tcb *tcp, const long addr);
#define print_timeval MPERS_PRINTER_NAME(print_timeval)

 void (*print_timeval_pair) (struct tcb *tcp, const long addr);
#define print_timeval_pair MPERS_PRINTER_NAME(print_timeval_pair)

 const char * (*sprint_timeval) (struct tcb *tcp, const long addr);
#define sprint_timeval MPERS_PRINTER_NAME(sprint_timeval)

 void (*print_itimerval) (struct tcb *tcp, const long addr);
#define print_itimerval MPERS_PRINTER_NAME(print_itimerval)

 int (*print_timex) (struct tcb *tcp, const long addr);
#define print_timex MPERS_PRINTER_NAME(print_timex)

 void (*printrusage) (struct tcb *tcp, long addr);
#define printrusage MPERS_PRINTER_NAME(printrusage)

 void (*printsiginfo_at) (struct tcb *tcp, long addr);
#define printsiginfo_at MPERS_PRINTER_NAME(printsiginfo_at)

} struct_printers;
extern const struct_printers *printers;
#define MPERS_PRINTER_NAME(printer_name) printers->printer_name
