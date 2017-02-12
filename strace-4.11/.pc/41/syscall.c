/*
 * Copyright (c) 1991, 1992 Paul Kranenburg <pk@cs.few.eur.nl>
 * Copyright (c) 1993 Branko Lankester <branko@hacktic.nl>
 * Copyright (c) 1993, 1994, 1995, 1996 Rick Sladkey <jrs@world.std.com>
 * Copyright (c) 1996-1999 Wichert Akkerman <wichert@cistron.nl>
 * Copyright (c) 1999 IBM Deutschland Entwicklung GmbH, IBM Corporation
 *                     Linux for s390 port by D.J. Barrow
 *                    <barrow_dj@mail.yahoo.com,djbarrow@de.ibm.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "defs.h"
#include "native_defs.h"
#include <sys/param.h>

/* for struct iovec */
#include <sys/uio.h>

#include "regs.h"
#include "ptrace.h"

#if defined(SPARC64)
# undef PTRACE_GETREGS
# define PTRACE_GETREGS PTRACE_GETREGS64
# undef PTRACE_SETREGS
# define PTRACE_SETREGS PTRACE_SETREGS64
#endif

#if defined SPARC64
# include <asm/psrcompat.h>
#elif defined SPARC
# include <asm/psr.h>
#endif

#ifdef IA64
# include <asm/rse.h>
#endif

#ifndef NT_PRSTATUS
# define NT_PRSTATUS 1
#endif

#ifndef NSIG
# warning: NSIG is not defined, using 32
# define NSIG 32
#endif

#include "syscall.h"

/* Define these shorthand notations to simplify the syscallent files. */
#define TD TRACE_DESC
#define TF TRACE_FILE
#define TI TRACE_IPC
#define TN TRACE_NETWORK
#define TP TRACE_PROCESS
#define TS TRACE_SIGNAL
#define TM TRACE_MEMORY
#define NF SYSCALL_NEVER_FAILS
#define MA MAX_ARGS
#define SI STACKTRACE_INVALIDATE_CACHE
#define SE STACKTRACE_CAPTURE_ON_ENTER

#define SEN(syscall_name) SEN_ ## syscall_name, SYS_FUNC_NAME(sys_ ## syscall_name)

const struct_sysent sysent0[] = {
#include "syscallent.h"
};

#if SUPPORTED_PERSONALITIES > 1
# include PERSONALITY1_INCLUDE_FUNCS
static const struct_sysent sysent1[] = {
# include "syscallent1.h"
};
#endif

#if SUPPORTED_PERSONALITIES > 2
# include PERSONALITY2_INCLUDE_FUNCS
static const struct_sysent sysent2[] = {
# include "syscallent2.h"
};
#endif

/* Now undef them since short defines cause wicked namespace pollution. */
#undef SEN
#undef TD
#undef TF
#undef TI
#undef TN
#undef TP
#undef TS
#undef TM
#undef NF
#undef MA
#undef SI
#undef SE

/*
 * `ioctlent[012].h' files are automatically generated by the auxiliary
 * program `ioctlsort', such that the list is sorted by the `code' field.
 * This has the side-effect of resolving the _IO.. macros into
 * plain integers, eliminating the need to include here everything
 * in "/usr/include".
 */

const char *const errnoent0[] = {
#include "errnoent.h"
};
const char *const signalent0[] = {
#include "signalent.h"
};
const struct_ioctlent ioctlent0[] = {
#include "ioctlent0.h"
};

#if SUPPORTED_PERSONALITIES > 1
static const char *const errnoent1[] = {
# include "errnoent1.h"
};
static const char *const signalent1[] = {
# include "signalent1.h"
};
static const struct_ioctlent ioctlent1[] = {
# include "ioctlent1.h"
};
# include PERSONALITY0_INCLUDE_PRINTERS_DECLS
static const struct_printers printers0 = {
# include PERSONALITY0_INCLUDE_PRINTERS_DEFS
};
# include PERSONALITY1_INCLUDE_PRINTERS_DECLS
static const struct_printers printers1 = {
# include PERSONALITY1_INCLUDE_PRINTERS_DEFS
};
#endif

#if SUPPORTED_PERSONALITIES > 2
static const char *const errnoent2[] = {
# include "errnoent2.h"
};
static const char *const signalent2[] = {
# include "signalent2.h"
};
static const struct_ioctlent ioctlent2[] = {
# include "ioctlent2.h"
};
# include PERSONALITY2_INCLUDE_PRINTERS_DECLS
static const struct_printers printers2 = {
# include PERSONALITY2_INCLUDE_PRINTERS_DEFS
};
#endif

enum {
	nsyscalls0 = ARRAY_SIZE(sysent0)
#if SUPPORTED_PERSONALITIES > 1
	, nsyscalls1 = ARRAY_SIZE(sysent1)
# if SUPPORTED_PERSONALITIES > 2
	, nsyscalls2 = ARRAY_SIZE(sysent2)
# endif
#endif
};

enum {
	nerrnos0 = ARRAY_SIZE(errnoent0)
#if SUPPORTED_PERSONALITIES > 1
	, nerrnos1 = ARRAY_SIZE(errnoent1)
# if SUPPORTED_PERSONALITIES > 2
	, nerrnos2 = ARRAY_SIZE(errnoent2)
# endif
#endif
};

enum {
	nsignals0 = ARRAY_SIZE(signalent0)
#if SUPPORTED_PERSONALITIES > 1
	, nsignals1 = ARRAY_SIZE(signalent1)
# if SUPPORTED_PERSONALITIES > 2
	, nsignals2 = ARRAY_SIZE(signalent2)
# endif
#endif
};

enum {
	nioctlents0 = ARRAY_SIZE(ioctlent0)
#if SUPPORTED_PERSONALITIES > 1
	, nioctlents1 = ARRAY_SIZE(ioctlent1)
# if SUPPORTED_PERSONALITIES > 2
	, nioctlents2 = ARRAY_SIZE(ioctlent2)
# endif
#endif
};

#if SUPPORTED_PERSONALITIES > 1
const struct_sysent *sysent = sysent0;
const char *const *errnoent = errnoent0;
const char *const *signalent = signalent0;
const struct_ioctlent *ioctlent = ioctlent0;
const struct_printers *printers = &printers0;
#endif

unsigned nsyscalls = nsyscalls0;
unsigned nerrnos = nerrnos0;
unsigned nsignals = nsignals0;
unsigned nioctlents = nioctlents0;

unsigned num_quals;
qualbits_t *qual_vec[SUPPORTED_PERSONALITIES];

static const unsigned nsyscall_vec[SUPPORTED_PERSONALITIES] = {
	nsyscalls0,
#if SUPPORTED_PERSONALITIES > 1
	nsyscalls1,
#endif
#if SUPPORTED_PERSONALITIES > 2
	nsyscalls2,
#endif
};
static const struct_sysent *const sysent_vec[SUPPORTED_PERSONALITIES] = {
	sysent0,
#if SUPPORTED_PERSONALITIES > 1
	sysent1,
#endif
#if SUPPORTED_PERSONALITIES > 2
	sysent2,
#endif
};

enum {
	MAX_NSYSCALLS1 = (nsyscalls0
#if SUPPORTED_PERSONALITIES > 1
			> nsyscalls1 ? nsyscalls0 : nsyscalls1
#endif
			),
	MAX_NSYSCALLS2 = (MAX_NSYSCALLS1
#if SUPPORTED_PERSONALITIES > 2
			> nsyscalls2 ? MAX_NSYSCALLS1 : nsyscalls2
#endif
			),
	MAX_NSYSCALLS = MAX_NSYSCALLS2,
	/* We are ready for arches with up to 255 signals,
	 * even though the largest known signo is on MIPS and it is 128.
	 * The number of existing syscalls on all arches is
	 * larger that 255 anyway, so it is just a pedantic matter.
	 */
	MIN_QUALS = MAX_NSYSCALLS > 255 ? MAX_NSYSCALLS : 255
};

#if SUPPORTED_PERSONALITIES > 1
unsigned current_personality;

# ifndef current_wordsize
unsigned current_wordsize;
static const int personality_wordsize[SUPPORTED_PERSONALITIES] = {
	PERSONALITY0_WORDSIZE,
	PERSONALITY1_WORDSIZE,
# if SUPPORTED_PERSONALITIES > 2
	PERSONALITY2_WORDSIZE,
# endif
};
# endif

void
set_personality(int personality)
{
	nsyscalls = nsyscall_vec[personality];
	sysent = sysent_vec[personality];

	switch (personality) {
	case 0:
		errnoent = errnoent0;
		nerrnos = nerrnos0;
		ioctlent = ioctlent0;
		nioctlents = nioctlents0;
		signalent = signalent0;
		nsignals = nsignals0;
		printers = &printers0;
		break;

	case 1:
		errnoent = errnoent1;
		nerrnos = nerrnos1;
		ioctlent = ioctlent1;
		nioctlents = nioctlents1;
		signalent = signalent1;
		nsignals = nsignals1;
		printers = &printers1;
		break;

# if SUPPORTED_PERSONALITIES > 2
	case 2:
		errnoent = errnoent2;
		nerrnos = nerrnos2;
		ioctlent = ioctlent2;
		nioctlents = nioctlents2;
		signalent = signalent2;
		nsignals = nsignals2;
		printers = &printers2;
		break;
# endif
	}

	current_personality = personality;
# ifndef current_wordsize
	current_wordsize = personality_wordsize[personality];
# endif
}

static void
update_personality(struct tcb *tcp, unsigned int personality)
{
	if (personality == current_personality)
		return;
	set_personality(personality);

	if (personality == tcp->currpers)
		return;
	tcp->currpers = personality;

# undef PERSONALITY_NAMES
# if defined POWERPC64
#  define PERSONALITY_NAMES {"64 bit", "32 bit"}
# elif defined X86_64
#  define PERSONALITY_NAMES {"64 bit", "32 bit", "x32"}
# elif defined X32
#  define PERSONALITY_NAMES {"x32", "32 bit"}
# elif defined AARCH64
#  define PERSONALITY_NAMES {"64 bit", "32 bit"}
# elif defined TILE
#  define PERSONALITY_NAMES {"64-bit", "32-bit"}
# endif
# ifdef PERSONALITY_NAMES
	if (!qflag) {
		static const char *const names[] = PERSONALITY_NAMES;
		error_msg("[ Process PID=%d runs in %s mode. ]",
			  tcp->pid, names[personality]);
	}
# endif
}
#endif

static int qual_syscall(), qual_signal(), qual_desc();

static const struct qual_options {
	unsigned int bitflag;
	const char *option_name;
	int (*qualify)(const char *, int, int);
	const char *argument_name;
} qual_options[] = {
	{ QUAL_TRACE,	"trace",	qual_syscall,	"system call"	},
	{ QUAL_TRACE,	"t",		qual_syscall,	"system call"	},
	{ QUAL_ABBREV,	"abbrev",	qual_syscall,	"system call"	},
	{ QUAL_ABBREV,	"a",		qual_syscall,	"system call"	},
	{ QUAL_VERBOSE,	"verbose",	qual_syscall,	"system call"	},
	{ QUAL_VERBOSE,	"v",		qual_syscall,	"system call"	},
	{ QUAL_RAW,	"raw",		qual_syscall,	"system call"	},
	{ QUAL_RAW,	"x",		qual_syscall,	"system call"	},
	{ QUAL_SIGNAL,	"signal",	qual_signal,	"signal"	},
	{ QUAL_SIGNAL,	"signals",	qual_signal,	"signal"	},
	{ QUAL_SIGNAL,	"s",		qual_signal,	"signal"	},
	{ QUAL_READ,	"read",		qual_desc,	"descriptor"	},
	{ QUAL_READ,	"reads",	qual_desc,	"descriptor"	},
	{ QUAL_READ,	"r",		qual_desc,	"descriptor"	},
	{ QUAL_WRITE,	"write",	qual_desc,	"descriptor"	},
	{ QUAL_WRITE,	"writes",	qual_desc,	"descriptor"	},
	{ QUAL_WRITE,	"w",		qual_desc,	"descriptor"	},
	{ 0,		NULL,		NULL,		NULL		},
};

static void
reallocate_qual(const unsigned int n)
{
	unsigned p;
	qualbits_t *qp;
	for (p = 0; p < SUPPORTED_PERSONALITIES; p++) {
		qp = qual_vec[p] = xreallocarray(qual_vec[p], n,
						 sizeof(qualbits_t));
		memset(&qp[num_quals], 0, (n - num_quals) * sizeof(qualbits_t));
	}
	num_quals = n;
}

static void
qualify_one(const unsigned int n, unsigned int bitflag, const int not, const int pers)
{
	int p;

	if (num_quals <= n)
		reallocate_qual(n + 1);

	for (p = 0; p < SUPPORTED_PERSONALITIES; p++) {
		if (pers == p || pers < 0) {
			if (not)
				qual_vec[p][n] &= ~bitflag;
			else
				qual_vec[p][n] |= bitflag;
		}
	}
}

static int
qual_syscall(const char *s, const unsigned int bitflag, const int not)
{
	int p;
	unsigned int i;
	int rc = -1;

	if (*s >= '0' && *s <= '9') {
		i = string_to_uint(s);
		if (i >= MAX_NSYSCALLS)
			return -1;
		qualify_one(i, bitflag, not, -1);
		return 0;
	}

	for (p = 0; p < SUPPORTED_PERSONALITIES; p++) {
		for (i = 0; i < nsyscall_vec[p]; i++) {
			if (sysent_vec[p][i].sys_name
			 && strcmp(s, sysent_vec[p][i].sys_name) == 0
			) {
				qualify_one(i, bitflag, not, p);
				rc = 0;
			}
		}
	}

	return rc;
}

static int
qual_signal(const char *s, const unsigned int bitflag, const int not)
{
	unsigned int i;

	if (*s >= '0' && *s <= '9') {
		int signo = string_to_uint(s);
		if (signo < 0 || signo > 255)
			return -1;
		qualify_one(signo, bitflag, not, -1);
		return 0;
	}
	if (strncasecmp(s, "SIG", 3) == 0)
		s += 3;
	for (i = 0; i <= NSIG; i++) {
		if (strcasecmp(s, signame(i) + 3) == 0) {
			qualify_one(i, bitflag, not, -1);
			return 0;
		}
	}
	return -1;
}

static int
qual_desc(const char *s, const unsigned int bitflag, const int not)
{
	if (*s >= '0' && *s <= '9') {
		int desc = string_to_uint(s);
		if (desc < 0 || desc > 0x7fff) /* paranoia */
			return -1;
		qualify_one(desc, bitflag, not, -1);
		return 0;
	}
	return -1;
}

static int
lookup_class(const char *s)
{
	if (strcmp(s, "file") == 0)
		return TRACE_FILE;
	if (strcmp(s, "ipc") == 0)
		return TRACE_IPC;
	if (strcmp(s, "network") == 0)
		return TRACE_NETWORK;
	if (strcmp(s, "process") == 0)
		return TRACE_PROCESS;
	if (strcmp(s, "signal") == 0)
		return TRACE_SIGNAL;
	if (strcmp(s, "desc") == 0)
		return TRACE_DESC;
	if (strcmp(s, "memory") == 0)
		return TRACE_MEMORY;
	return -1;
}

void
qualify(const char *s)
{
	const struct qual_options *opt;
	char *copy;
	const char *p;
	int not;
	unsigned int i;

	if (num_quals == 0)
		reallocate_qual(MIN_QUALS);

	opt = &qual_options[0];
	for (i = 0; (p = qual_options[i].option_name); i++) {
		unsigned int len = strlen(p);
		if (strncmp(s, p, len) == 0 && s[len] == '=') {
			opt = &qual_options[i];
			s += len + 1;
			break;
		}
	}
	not = 0;
	if (*s == '!') {
		not = 1;
		s++;
	}
	if (strcmp(s, "none") == 0) {
		not = 1 - not;
		s = "all";
	}
	if (strcmp(s, "all") == 0) {
		for (i = 0; i < num_quals; i++) {
			qualify_one(i, opt->bitflag, not, -1);
		}
		return;
	}
	for (i = 0; i < num_quals; i++) {
		qualify_one(i, opt->bitflag, !not, -1);
	}
	copy = xstrdup(s);
	for (p = strtok(copy, ","); p; p = strtok(NULL, ",")) {
		int n;
		if (opt->bitflag == QUAL_TRACE && (n = lookup_class(p)) > 0) {
			unsigned pers;
			for (pers = 0; pers < SUPPORTED_PERSONALITIES; pers++) {
				for (i = 0; i < nsyscall_vec[pers]; i++)
					if (sysent_vec[pers][i].sys_flags & n)
						qualify_one(i, opt->bitflag, not, pers);
			}
			continue;
		}
		if (opt->qualify(p, opt->bitflag, not)) {
			error_msg_and_die("invalid %s '%s'",
				opt->argument_name, p);
		}
	}
	free(copy);
	return;
}

#ifdef SYS_socket_subcall
static void
decode_socket_subcall(struct tcb *tcp)
{
	unsigned long addr;
	unsigned int n;

	if (tcp->u_arg[0] < 0 || tcp->u_arg[0] >= SYS_socket_nsubcalls)
		return;

	tcp->scno = SYS_socket_subcall + tcp->u_arg[0];
	tcp->qual_flg = qual_flags[tcp->scno];
	tcp->s_ent = &sysent[tcp->scno];
	addr = tcp->u_arg[1];
	n = tcp->s_ent->nargs;
	if (sizeof(tcp->u_arg[0]) == current_wordsize) {
		memset(tcp->u_arg, 0, n * sizeof(tcp->u_arg[0]));
		(void) umoven(tcp, addr, n * sizeof(tcp->u_arg[0]), tcp->u_arg);
	} else {
		unsigned int args[n];
		unsigned int i;

		memset(args, 0, sizeof(args));
		(void) umove(tcp, addr, &args);
		for (i = 0; i < n; ++i)
			tcp->u_arg[i] = args[i];
	}
}
#endif

#ifdef SYS_ipc_subcall
static void
decode_ipc_subcall(struct tcb *tcp)
{
	unsigned int i, n;

	if (tcp->u_arg[0] < 0 || tcp->u_arg[0] >= SYS_ipc_nsubcalls)
		return;

	tcp->scno = SYS_ipc_subcall + tcp->u_arg[0];
	tcp->qual_flg = qual_flags[tcp->scno];
	tcp->s_ent = &sysent[tcp->scno];
	n = tcp->s_ent->nargs;
	for (i = 0; i < n; i++)
		tcp->u_arg[i] = tcp->u_arg[i + 1];
}
#endif

#ifdef LINUX_MIPSO32
static void
decode_mips_subcall(struct tcb *tcp)
{
	if (!SCNO_IS_VALID(tcp->u_arg[0]))
		return;
	tcp->scno = tcp->u_arg[0];
	tcp->qual_flg = qual_flags[tcp->scno];
	tcp->s_ent = &sysent[tcp->scno];
	memmove(&tcp->u_arg[0], &tcp->u_arg[1],
		sizeof(tcp->u_arg) - sizeof(tcp->u_arg[0]));
	/*
	 * Fetching the last arg of 7-arg syscalls (fadvise64_64
	 * and sync_file_range) would require additional code,
	 * see linux/mips/get_syscall_args.c
	 */
}

SYS_FUNC(syscall)
{
	return printargs(tcp);
}
#endif

int
printargs(struct tcb *tcp)
{
	if (entering(tcp)) {
		int i;
		int n = tcp->s_ent->nargs;
		for (i = 0; i < n; i++)
			tprintf("%s%#lx", i ? ", " : "", tcp->u_arg[i]);
	}
	return 0;
}

int
printargs_lu(struct tcb *tcp)
{
	if (entering(tcp)) {
		int i;
		int n = tcp->s_ent->nargs;
		for (i = 0; i < n; i++)
			tprintf("%s%lu", i ? ", " : "", tcp->u_arg[i]);
	}
	return 0;
}

int
printargs_ld(struct tcb *tcp)
{
	if (entering(tcp)) {
		int i;
		int n = tcp->s_ent->nargs;
		for (i = 0; i < n; i++)
			tprintf("%s%ld", i ? ", " : "", tcp->u_arg[i]);
	}
	return 0;
}

static void
dumpio(struct tcb *tcp)
{
	int sen;

	if (syserror(tcp))
		return;
	if ((unsigned long) tcp->u_arg[0] >= num_quals)
		return;
	sen = tcp->s_ent->sen;
	if (SEN_printargs == sen)
		return;
	if (qual_flags[tcp->u_arg[0]] & QUAL_READ) {
		switch (sen) {
		case SEN_read:
		case SEN_pread:
		case SEN_recv:
		case SEN_recvfrom:
			dumpstr(tcp, tcp->u_arg[1], tcp->u_rval);
			return;
		case SEN_readv:
			dumpiov(tcp, tcp->u_arg[2], tcp->u_arg[1]);
			return;
		case SEN_recvmsg:
			dumpiov_in_msghdr(tcp, tcp->u_arg[1]);
			return;
		case SEN_recvmmsg:
			dumpiov_in_mmsghdr(tcp, tcp->u_arg[1]);
			return;
		}
	}
	if (qual_flags[tcp->u_arg[0]] & QUAL_WRITE) {
		switch (sen) {
		case SEN_write:
		case SEN_pwrite:
		case SEN_send:
		case SEN_sendto:
			dumpstr(tcp, tcp->u_arg[1], tcp->u_arg[2]);
			break;
		case SEN_writev:
			dumpiov(tcp, tcp->u_arg[2], tcp->u_arg[1]);
			break;
		case SEN_sendmsg:
			dumpiov_in_msghdr(tcp, tcp->u_arg[1]);
			break;
		case SEN_sendmmsg:
			dumpiov_in_mmsghdr(tcp, tcp->u_arg[1]);
			break;
		}
	}
}

/*
 * Shuffle syscall numbers so that we don't have huge gaps in syscall table.
 * The shuffling should be an involution: shuffle_scno(shuffle_scno(n)) == n.
 */
#if defined(ARM) || defined(AARCH64) /* So far only 32-bit ARM needs this */
static long
shuffle_scno(unsigned long scno)
{
	if (scno < ARM_FIRST_SHUFFLED_SYSCALL)
		return scno;

	/* __ARM_NR_cmpxchg? Swap with LAST_ORDINARY+1 */
	if (scno == ARM_FIRST_SHUFFLED_SYSCALL)
		return 0x000ffff0;
	if (scno == 0x000ffff0)
		return ARM_FIRST_SHUFFLED_SYSCALL;

#define ARM_SECOND_SHUFFLED_SYSCALL (ARM_FIRST_SHUFFLED_SYSCALL + 1)
	/*
	 * Is it ARM specific syscall?
	 * Swap [0x000f0000, 0x000f0000 + LAST_SPECIAL] range
	 * with [SECOND_SHUFFLED, SECOND_SHUFFLED + LAST_SPECIAL] range.
	 */
	if (scno >= 0x000f0000 &&
	    scno <= 0x000f0000 + ARM_LAST_SPECIAL_SYSCALL) {
		return scno - 0x000f0000 + ARM_SECOND_SHUFFLED_SYSCALL;
	}
	if (scno <= ARM_SECOND_SHUFFLED_SYSCALL + ARM_LAST_SPECIAL_SYSCALL) {
		return scno + 0x000f0000 - ARM_SECOND_SHUFFLED_SYSCALL;
	}

	return scno;
}
#else
# define shuffle_scno(scno) ((long)(scno))
#endif

const char *
syscall_name(long scno)
{
	static char buf[sizeof("syscall_%lu") + sizeof(long)*3];

	if (SCNO_IS_VALID(scno))
		return sysent[scno].sys_name;
	else {
		sprintf(buf, "syscall_%lu", shuffle_scno(scno));
		return buf;
	}
}

static long get_regs_error;

void
clear_regs(void)
{
	get_regs_error = -1;
}

static int get_syscall_args(struct tcb *);
static int get_syscall_result(struct tcb *);
static int arch_get_scno(struct tcb *tcp);
static void get_error(struct tcb *, const bool);
#if defined X86_64 || defined POWERPC
static int getregs_old(pid_t);
#endif

static int
trace_syscall_entering(struct tcb *tcp)
{
	int res, scno_good;

	scno_good = res = get_scno(tcp);
	if (res == 0)
		return res;
	if (res == 1)
		res = get_syscall_args(tcp);
        tprintf("\nmym_scno=%ld\n", (tcp->scno));

	if (res != 1) {
		printleader(tcp);
		if (scno_good != 1)
			tprints("????" /* anti-trigraph gap */ "(");
		else if (tcp->qual_flg & UNDEFINED_SCNO)
			tprintf("%s(", syscall_name(tcp->scno));
		else
			tprintf("%s(", tcp->s_ent->sys_name);
		/*
		 * " <unavailable>" will be added later by the code which
		 * detects ptrace errors.
		 */
		goto ret;
	}

#ifdef LINUX_MIPSO32
	if (SEN_syscall == tcp->s_ent->sen)
		decode_mips_subcall(tcp);
#endif

	if (   SEN_execve == tcp->s_ent->sen
# if defined(SPARC) || defined(SPARC64)
	    || SEN_execv == tcp->s_ent->sen
# endif
	   ) {
		hide_log_until_execve = 0;
	}

#if defined(SYS_socket_subcall) || defined(SYS_ipc_subcall)
	switch (tcp->s_ent->sen) {
# ifdef SYS_socket_subcall
		case SEN_socketcall:
			decode_socket_subcall(tcp);
			break;
# endif
# ifdef SYS_ipc_subcall
		case SEN_ipc:
			decode_ipc_subcall(tcp);
			break;
# endif
	}
#endif

	if (!(tcp->qual_flg & QUAL_TRACE)
	 || (tracing_paths && !pathtrace_match(tcp))
	) {
		tcp->flags |= TCB_INSYSCALL | TCB_FILTERED;
		tcp->sys_func_rval = 0;
		return 0;
	}

	tcp->flags &= ~TCB_FILTERED;

	if (cflag == CFLAG_ONLY_STATS || hide_log_until_execve) {
		res = 0;
		goto ret;
	}

#ifdef USE_LIBUNWIND
	if (stack_trace_enabled) {
		if (tcp->s_ent->sys_flags & STACKTRACE_CAPTURE_ON_ENTER)
			unwind_capture_stacktrace(tcp);
	}
#endif

	printleader(tcp);
	if (tcp->qual_flg & UNDEFINED_SCNO)
		tprintf("%s(", syscall_name(tcp->scno));
	else
		tprintf("%s(", tcp->s_ent->sys_name);
	if ((tcp->qual_flg & QUAL_RAW) && SEN_exit != tcp->s_ent->sen)
		res = printargs(tcp);
	else
		res = tcp->s_ent->sys_func(tcp);

	fflush(tcp->outf);
 ret:
	tcp->flags |= TCB_INSYSCALL;
	tcp->sys_func_rval = res;
	/* Measure the entrance time as late as possible to avoid errors. */
	if (Tflag || cflag)
		gettimeofday(&tcp->etime, NULL);
	return res;
}

static int
trace_syscall_exiting(struct tcb *tcp)
{
	int sys_res;
	struct timeval tv;
	int res;
	long u_error;

	/* Measure the exit time as early as possible to avoid errors. */
	if (Tflag || cflag)
		gettimeofday(&tv, NULL);

#ifdef USE_LIBUNWIND
	if (stack_trace_enabled) {
		if (tcp->s_ent->sys_flags & STACKTRACE_INVALIDATE_CACHE)
			unwind_cache_invalidate(tcp);
	}
#endif

#if SUPPORTED_PERSONALITIES > 1
	update_personality(tcp, tcp->currpers);
#endif
	res = (get_regs_error ? -1 : get_syscall_result(tcp));
	if (filtered(tcp) || hide_log_until_execve)
		goto ret;

	if (cflag) {
		count_syscall(tcp, &tv);
		if (cflag == CFLAG_ONLY_STATS) {
			goto ret;
		}
	}

	/* If not in -ff mode, and printing_tcp != tcp,
	 * then the log currently does not end with output
	 * of _our syscall entry_, but with something else.
	 * We need to say which syscall's return is this.
	 *
	 * Forced reprinting via TCB_REPRINT is used only by
	 * "strace -ff -oLOG test/threaded_execve" corner case.
	 * It's the only case when -ff mode needs reprinting.
	 */
	if ((followfork < 2 && printing_tcp != tcp) || (tcp->flags & TCB_REPRINT)) {
		tcp->flags &= ~TCB_REPRINT;
		printleader(tcp);
		if (tcp->qual_flg & UNDEFINED_SCNO)
			tprintf("<... %s resumed> ", syscall_name(tcp->scno));
		else
			tprintf("<... %s resumed> ", tcp->s_ent->sys_name);
	}
	printing_tcp = tcp;

	tcp->s_prev_ent = NULL;
	if (res != 1) {
		/* There was error in one of prior ptrace ops */
		tprints(") ");
		tabto();
		tprints("= ? <unavailable>\n");
		line_ended();
		tcp->flags &= ~TCB_INSYSCALL;
		tcp->sys_func_rval = 0;
		return res;
	}
	tcp->s_prev_ent = tcp->s_ent;

	sys_res = 0;
	if (tcp->qual_flg & QUAL_RAW) {
		/* sys_res = printargs(tcp); - but it's nop on sysexit */
	} else {
	/* FIXME: not_failing_only (IOW, option -z) is broken:
	 * failure of syscall is known only after syscall return.
	 * Thus we end up with something like this on, say, ENOENT:
	 *     open("doesnt_exist", O_RDONLY <unfinished ...>
	 *     {next syscall decode}
	 * whereas the intended result is that open(...) line
	 * is not shown at all.
	 */
		if (not_failing_only && tcp->u_error)
			goto ret;	/* ignore failed syscalls */
		if (tcp->sys_func_rval & RVAL_DECODED)
			sys_res = tcp->sys_func_rval;
		else
			sys_res = tcp->s_ent->sys_func(tcp);
	}
        tprintf("\nmym_scall_rval=%#lx\n", tcp->u_rval);
	tprints(") ");
	tabto();
	u_error = tcp->u_error;
	if (tcp->qual_flg & QUAL_RAW) {
		if (u_error)
			tprintf("= -1 (errno %ld)", u_error);
		else
			tprintf("= %#lx", tcp->u_rval);
	}
	else if (!(sys_res & RVAL_NONE) && u_error) {
		switch (u_error) {
		/* Blocked signals do not interrupt any syscalls.
		 * In this case syscalls don't return ERESTARTfoo codes.
		 *
		 * Deadly signals set to SIG_DFL interrupt syscalls
		 * and kill the process regardless of which of the codes below
		 * is returned by the interrupted syscall.
		 * In some cases, kernel forces a kernel-generated deadly
		 * signal to be unblocked and set to SIG_DFL (and thus cause
		 * death) if it is blocked or SIG_IGNed: for example, SIGSEGV
		 * or SIGILL. (The alternative is to leave process spinning
		 * forever on the faulty instruction - not useful).
		 *
		 * SIG_IGNed signals and non-deadly signals set to SIG_DFL
		 * (for example, SIGCHLD, SIGWINCH) interrupt syscalls,
		 * but kernel will always restart them.
		 */
		case ERESTARTSYS:
			/* Most common type of signal-interrupted syscall exit code.
			 * The system call will be restarted with the same arguments
			 * if SA_RESTART is set; otherwise, it will fail with EINTR.
			 */
			tprints("= ? ERESTARTSYS (To be restarted if SA_RESTART is set)");
			break;
		case ERESTARTNOINTR:
			/* Rare. For example, fork() returns this if interrupted.
			 * SA_RESTART is ignored (assumed set): the restart is unconditional.
			 */
			tprints("= ? ERESTARTNOINTR (To be restarted)");
			break;
		case ERESTARTNOHAND:
			/* pause(), rt_sigsuspend() etc use this code.
			 * SA_RESTART is ignored (assumed not set):
			 * syscall won't restart (will return EINTR instead)
			 * even after signal with SA_RESTART set. However,
			 * after SIG_IGN or SIG_DFL signal it will restart
			 * (thus the name "restart only if has no handler").
			 */
			tprints("= ? ERESTARTNOHAND (To be restarted if no handler)");
			break;
		case ERESTART_RESTARTBLOCK:
			/* Syscalls like nanosleep(), poll() which can't be
			 * restarted with their original arguments use this
			 * code. Kernel will execute restart_syscall() instead,
			 * which changes arguments before restarting syscall.
			 * SA_RESTART is ignored (assumed not set) similarly
			 * to ERESTARTNOHAND. (Kernel can't honor SA_RESTART
			 * since restart data is saved in "restart block"
			 * in task struct, and if signal handler uses a syscall
			 * which in turn saves another such restart block,
			 * old data is lost and restart becomes impossible)
			 */
			tprints("= ? ERESTART_RESTARTBLOCK (Interrupted by signal)");
			break;
		default:
			if ((unsigned long) u_error < nerrnos
			    && errnoent[u_error])
				tprintf("= -1 %s (%s)", errnoent[u_error],
					strerror(u_error));
			else
				tprintf("= -1 ERRNO_%lu (%s)", u_error,
					strerror(u_error));
			break;
		}
		if ((sys_res & RVAL_STR) && tcp->auxstr)
			tprintf(" (%s)", tcp->auxstr);
	}
	else {
		if (sys_res & RVAL_NONE)
			tprints("= ?");
		else {
			switch (sys_res & RVAL_MASK) {
			case RVAL_HEX:
#if SUPPORTED_PERSONALITIES > 1
				if (current_wordsize < sizeof(long))
					tprintf("= %#x",
						(unsigned int) tcp->u_rval);
				else
#endif
					tprintf("= %#lx", tcp->u_rval);
				break;
			case RVAL_OCTAL:
				tprintf("= %#lo", tcp->u_rval);
				break;
			case RVAL_UDECIMAL:
#if SUPPORTED_PERSONALITIES > 1
				if (current_wordsize < sizeof(long))
					tprintf("= %u",
						(unsigned int) tcp->u_rval);
				else
#endif
					tprintf("= %lu", tcp->u_rval);
				break;
			case RVAL_DECIMAL:
				tprintf("= %ld", tcp->u_rval);
				break;
			case RVAL_FD:
				if (show_fd_path) {
					tprints("= ");
					printfd(tcp, tcp->u_rval);
				}
				else
					tprintf("= %ld", tcp->u_rval);
				break;
#if defined(LINUX_MIPSN32) || defined(X32)
			/*
			case RVAL_LHEX:
				tprintf("= %#llx", tcp->u_lrval);
				break;
			case RVAL_LOCTAL:
				tprintf("= %#llo", tcp->u_lrval);
				break;
			*/
			case RVAL_LUDECIMAL:
				tprintf("= %llu", tcp->u_lrval);
				break;
			/*
			case RVAL_LDECIMAL:
				tprintf("= %lld", tcp->u_lrval);
				break;
			*/
#endif
			default:
				error_msg("invalid rval format");
				break;
			}
		}
		if ((sys_res & RVAL_STR) && tcp->auxstr)
			tprintf(" (%s)", tcp->auxstr);
	}
	if (Tflag) {
		tv_sub(&tv, &tv, &tcp->etime);
		tprintf(" <%ld.%06ld>",
			(long) tv.tv_sec, (long) tv.tv_usec);
	}
	tprints("\n");
	dumpio(tcp);
	line_ended();

#ifdef USE_LIBUNWIND
	if (stack_trace_enabled)
		unwind_print_stacktrace(tcp);
#endif

 ret:
	tcp->flags &= ~TCB_INSYSCALL;
	tcp->sys_func_rval = 0;
	return 0;
}

int
trace_syscall(struct tcb *tcp)
{
	return exiting(tcp) ?
		trace_syscall_exiting(tcp) : trace_syscall_entering(tcp);
}

bool
is_erestart(struct tcb *tcp)
{
	switch (tcp->u_error) {
		case ERESTARTSYS:
		case ERESTARTNOINTR:
		case ERESTARTNOHAND:
		case ERESTART_RESTARTBLOCK:
			return true;
		default:
			return false;
	}
}

static int saved_u_error;

void
temporarily_clear_syserror(struct tcb *tcp)
{
	saved_u_error = tcp->u_error;
	tcp->u_error = 0;
}

void
restore_cleared_syserror(struct tcb *tcp)
{
	tcp->u_error = saved_u_error;
}

#include "kernel_types.h"

/*
 * Check the syscall return value register value for whether it is
 * a negated errno code indicating an error, or a success return value.
 */
static inline bool
is_negated_errno(kernel_ulong_t val)
{
	/* Linux kernel defines MAX_ERRNO to 4095. */
	kernel_ulong_t max = -(kernel_long_t) 4095;

#if SUPPORTED_PERSONALITIES > 1 && SIZEOF_LONG > 4
	if (current_wordsize < sizeof(val)) {
		val = (uint32_t) val;
		max = (uint32_t) max;
	}
#elif defined X32
	/*
	 * current_wordsize is 4 even in personality 0 (native X32)
	 * but truncation _must not_ be done in it.
	 * can't check current_wordsize here!
	 */
	if (current_personality != 0) {
		val = (uint32_t) val;
		max = (uint32_t) max;
	}
#endif

	return val >= max;
}

#include "arch_regs.c"

#ifdef HAVE_GETRVAL2
# include "arch_getrval2.c"
#endif

void
print_pc(struct tcb *tcp)
{
#if defined ARCH_PC_REG
# define ARCH_GET_PC 0
#elif defined ARCH_PC_PEEK_ADDR
	long pc;
# define ARCH_PC_REG pc
# define ARCH_GET_PC upeek(tcp->pid, ARCH_PC_PEEK_ADDR, &pc)
#else
# error Neither ARCH_PC_REG nor ARCH_PC_PEEK_ADDR is defined
#endif
	if (get_regs_error || ARCH_GET_PC)
		tprints(current_wordsize == 4 ? "[????????] "
					      : "[????????????????] ");
	else
		tprintf(current_wordsize == 4 ? "[%08lx] " : "[%016lx] ",
			(unsigned long) ARCH_PC_REG);
}

#if defined ARCH_REGS_FOR_GETREGSET
static long
get_regset(pid_t pid)
{
# ifdef ARCH_IOVEC_FOR_GETREGSET
	/* variable iovec */
	ARCH_IOVEC_FOR_GETREGSET.iov_len = sizeof(ARCH_REGS_FOR_GETREGSET);
	return ptrace(PTRACE_GETREGSET, pid, NT_PRSTATUS,
		      &ARCH_IOVEC_FOR_GETREGSET);
# else
	/* constant iovec */
	static struct iovec io = {
		.iov_base = &ARCH_REGS_FOR_GETREGSET,
		.iov_len = sizeof(ARCH_REGS_FOR_GETREGSET)
	};
	return ptrace(PTRACE_GETREGSET, pid, NT_PRSTATUS, &io);

# endif
}
#endif /* ARCH_REGS_FOR_GETREGSET */

void
get_regs(pid_t pid)
{
#undef USE_GET_SYSCALL_RESULT_REGS
#ifdef ARCH_REGS_FOR_GETREGSET
# ifdef X86_64
	/* Try PTRACE_GETREGSET first, fallback to PTRACE_GETREGS. */
	static int getregset_support;

	if (getregset_support >= 0) {
		get_regs_error = get_regset(pid);
		if (getregset_support > 0)
			return;
		if (get_regs_error >= 0) {
			getregset_support = 1;
			return;
		}
		if (errno == EPERM || errno == ESRCH)
			return;
		getregset_support = -1;
	}
	get_regs_error = getregs_old(pid);
# else /* !X86_64 */
	/* Assume that PTRACE_GETREGSET works. */
	get_regs_error = get_regset(pid);
# endif
#elif defined ARCH_REGS_FOR_GETREGS
# if defined SPARC || defined SPARC64
	/* SPARC systems have the meaning of data and addr reversed */
	get_regs_error = ptrace(PTRACE_GETREGS, pid, (char *)&ARCH_REGS_FOR_GETREGS, 0);
# elif defined POWERPC
	static bool old_kernel = 0;
	if (old_kernel)
		goto old;
	get_regs_error = ptrace(PTRACE_GETREGS, pid, NULL, &ARCH_REGS_FOR_GETREGS);
	if (get_regs_error && errno == EIO) {
		old_kernel = 1;
 old:
		get_regs_error = getregs_old(pid);
	}
# else
	/* Assume that PTRACE_GETREGS works. */
	get_regs_error = ptrace(PTRACE_GETREGS, pid, NULL, &ARCH_REGS_FOR_GETREGS);
# endif

#else /* !ARCH_REGS_FOR_GETREGSET && !ARCH_REGS_FOR_GETREGS */
# define USE_GET_SYSCALL_RESULT_REGS 1
# warning get_regs is not implemented for this architecture yet
	get_regs_error = 0;
#endif
}

/*
 * Returns:
 * 0: "ignore this ptrace stop", bail out of trace_syscall_entering() silently.
 * 1: ok, continue in trace_syscall_entering().
 * other: error, trace_syscall_entering() should print error indicator
 *    ("????" etc) and bail out.
 */
int
get_scno(struct tcb *tcp)
{
	if (get_regs_error)
		return -1;

	int rc = arch_get_scno(tcp);
	if (rc != 1)
		return rc;

	if (SCNO_IS_VALID(tcp->scno)) {
		tcp->s_ent = &sysent[tcp->scno];
		tcp->qual_flg = qual_flags[tcp->scno];
	} else {
		static const struct_sysent unknown = {
			.nargs = MAX_ARGS,
			.sys_flags = 0,
			.sys_func = printargs,
			.sys_name = "system call",
		};
		tcp->s_ent = &unknown;
		tcp->qual_flg = UNDEFINED_SCNO | QUAL_RAW | DEFAULT_QUAL_FLAGS;
		if (debug_flag)
			error_msg("pid %d invalid syscall %ld", tcp->pid, tcp->scno);
	}
	return 1;
}

#ifdef USE_GET_SYSCALL_RESULT_REGS
static int get_syscall_result_regs(struct tcb *);
#endif

/* Returns:
 * 1: ok, continue in trace_syscall_exiting().
 * -1: error, trace_syscall_exiting() should print error indicator
 *    ("????" etc) and bail out.
 */
static int
get_syscall_result(struct tcb *tcp)
{
#ifdef USE_GET_SYSCALL_RESULT_REGS
	if (get_syscall_result_regs(tcp))
		return -1;
#endif
	tcp->u_error = 0;
	get_error(tcp, !(tcp->s_ent->sys_flags & SYSCALL_NEVER_FAILS));

	return 1;
}

#include "get_scno.c"
#include "get_syscall_args.c"
#ifdef USE_GET_SYSCALL_RESULT_REGS
# include "get_syscall_result.c"
#endif
#include "get_error.c"
#if defined X86_64 || defined POWERPC
# include "getregs_old.c"
#endif
