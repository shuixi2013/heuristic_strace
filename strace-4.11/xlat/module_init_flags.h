/* Generated by ./xlat/gen.sh from ./xlat/module_init_flags.in; do not edit. */

#ifdef IN_MPERS

# error static const struct xlat module_init_flags in mpers mode

#else

static
const struct xlat module_init_flags[] = {
#if defined(MODULE_INIT_IGNORE_MODVERSIONS) || (defined(HAVE_DECL_MODULE_INIT_IGNORE_MODVERSIONS) && HAVE_DECL_MODULE_INIT_IGNORE_MODVERSIONS)
  XLAT(MODULE_INIT_IGNORE_MODVERSIONS),
#endif
#if defined(MODULE_INIT_IGNORE_VERMAGIC) || (defined(HAVE_DECL_MODULE_INIT_IGNORE_VERMAGIC) && HAVE_DECL_MODULE_INIT_IGNORE_VERMAGIC)
  XLAT(MODULE_INIT_IGNORE_VERMAGIC),
#endif
 XLAT_END
};

#endif /* !IN_MPERS */
