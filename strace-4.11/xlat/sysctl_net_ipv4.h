/* Generated by ./xlat/gen.sh from ./xlat/sysctl_net_ipv4.in; do not edit. */

#ifdef IN_MPERS

# error static const struct xlat sysctl_net_ipv4 in mpers mode

#else

static
const struct xlat sysctl_net_ipv4[] = {
#if defined(NET_IPV4_FORWARD) || (defined(HAVE_DECL_NET_IPV4_FORWARD) && HAVE_DECL_NET_IPV4_FORWARD)
  XLAT(NET_IPV4_FORWARD),
#endif
#if defined(NET_IPV4_DYNADDR) || (defined(HAVE_DECL_NET_IPV4_DYNADDR) && HAVE_DECL_NET_IPV4_DYNADDR)
  XLAT(NET_IPV4_DYNADDR),
#endif
#if defined(NET_IPV4_CONF) || (defined(HAVE_DECL_NET_IPV4_CONF) && HAVE_DECL_NET_IPV4_CONF)
  XLAT(NET_IPV4_CONF),
#endif
#if defined(NET_IPV4_NEIGH) || (defined(HAVE_DECL_NET_IPV4_NEIGH) && HAVE_DECL_NET_IPV4_NEIGH)
  XLAT(NET_IPV4_NEIGH),
#endif
#if defined(NET_IPV4_ROUTE) || (defined(HAVE_DECL_NET_IPV4_ROUTE) && HAVE_DECL_NET_IPV4_ROUTE)
  XLAT(NET_IPV4_ROUTE),
#endif
#if defined(NET_IPV4_FIB_HASH) || (defined(HAVE_DECL_NET_IPV4_FIB_HASH) && HAVE_DECL_NET_IPV4_FIB_HASH)
  XLAT(NET_IPV4_FIB_HASH),
#endif
#if defined(NET_IPV4_NETFILTER) || (defined(HAVE_DECL_NET_IPV4_NETFILTER) && HAVE_DECL_NET_IPV4_NETFILTER)
  XLAT(NET_IPV4_NETFILTER),
#endif
#if defined(NET_IPV4_TCP_TIMESTAMPS) || (defined(HAVE_DECL_NET_IPV4_TCP_TIMESTAMPS) && HAVE_DECL_NET_IPV4_TCP_TIMESTAMPS)
  XLAT(NET_IPV4_TCP_TIMESTAMPS),
#endif
#if defined(NET_IPV4_TCP_WINDOW_SCALING) || (defined(HAVE_DECL_NET_IPV4_TCP_WINDOW_SCALING) && HAVE_DECL_NET_IPV4_TCP_WINDOW_SCALING)
  XLAT(NET_IPV4_TCP_WINDOW_SCALING),
#endif
#if defined(NET_IPV4_TCP_SACK) || (defined(HAVE_DECL_NET_IPV4_TCP_SACK) && HAVE_DECL_NET_IPV4_TCP_SACK)
  XLAT(NET_IPV4_TCP_SACK),
#endif
#if defined(NET_IPV4_TCP_RETRANS_COLLAPSE) || (defined(HAVE_DECL_NET_IPV4_TCP_RETRANS_COLLAPSE) && HAVE_DECL_NET_IPV4_TCP_RETRANS_COLLAPSE)
  XLAT(NET_IPV4_TCP_RETRANS_COLLAPSE),
#endif
#if defined(NET_IPV4_DEFAULT_TTL) || (defined(HAVE_DECL_NET_IPV4_DEFAULT_TTL) && HAVE_DECL_NET_IPV4_DEFAULT_TTL)
  XLAT(NET_IPV4_DEFAULT_TTL),
#endif
#if defined(NET_IPV4_AUTOCONFIG) || (defined(HAVE_DECL_NET_IPV4_AUTOCONFIG) && HAVE_DECL_NET_IPV4_AUTOCONFIG)
  XLAT(NET_IPV4_AUTOCONFIG),
#endif
#if defined(NET_IPV4_NO_PMTU_DISC) || (defined(HAVE_DECL_NET_IPV4_NO_PMTU_DISC) && HAVE_DECL_NET_IPV4_NO_PMTU_DISC)
  XLAT(NET_IPV4_NO_PMTU_DISC),
#endif
#if defined(NET_IPV4_TCP_SYN_RETRIES) || (defined(HAVE_DECL_NET_IPV4_TCP_SYN_RETRIES) && HAVE_DECL_NET_IPV4_TCP_SYN_RETRIES)
  XLAT(NET_IPV4_TCP_SYN_RETRIES),
#endif
#if defined(NET_IPV4_IPFRAG_HIGH_THRESH) || (defined(HAVE_DECL_NET_IPV4_IPFRAG_HIGH_THRESH) && HAVE_DECL_NET_IPV4_IPFRAG_HIGH_THRESH)
  XLAT(NET_IPV4_IPFRAG_HIGH_THRESH),
#endif
#if defined(NET_IPV4_IPFRAG_LOW_THRESH) || (defined(HAVE_DECL_NET_IPV4_IPFRAG_LOW_THRESH) && HAVE_DECL_NET_IPV4_IPFRAG_LOW_THRESH)
  XLAT(NET_IPV4_IPFRAG_LOW_THRESH),
#endif
#if defined(NET_IPV4_IPFRAG_TIME) || (defined(HAVE_DECL_NET_IPV4_IPFRAG_TIME) && HAVE_DECL_NET_IPV4_IPFRAG_TIME)
  XLAT(NET_IPV4_IPFRAG_TIME),
#endif
#if defined(NET_IPV4_TCP_MAX_KA_PROBES) || (defined(HAVE_DECL_NET_IPV4_TCP_MAX_KA_PROBES) && HAVE_DECL_NET_IPV4_TCP_MAX_KA_PROBES)
  XLAT(NET_IPV4_TCP_MAX_KA_PROBES),
#endif
#if defined(NET_IPV4_TCP_KEEPALIVE_TIME) || (defined(HAVE_DECL_NET_IPV4_TCP_KEEPALIVE_TIME) && HAVE_DECL_NET_IPV4_TCP_KEEPALIVE_TIME)
  XLAT(NET_IPV4_TCP_KEEPALIVE_TIME),
#endif
#if defined(NET_IPV4_TCP_KEEPALIVE_PROBES) || (defined(HAVE_DECL_NET_IPV4_TCP_KEEPALIVE_PROBES) && HAVE_DECL_NET_IPV4_TCP_KEEPALIVE_PROBES)
  XLAT(NET_IPV4_TCP_KEEPALIVE_PROBES),
#endif
#if defined(NET_IPV4_TCP_RETRIES1) || (defined(HAVE_DECL_NET_IPV4_TCP_RETRIES1) && HAVE_DECL_NET_IPV4_TCP_RETRIES1)
  XLAT(NET_IPV4_TCP_RETRIES1),
#endif
#if defined(NET_IPV4_TCP_RETRIES2) || (defined(HAVE_DECL_NET_IPV4_TCP_RETRIES2) && HAVE_DECL_NET_IPV4_TCP_RETRIES2)
  XLAT(NET_IPV4_TCP_RETRIES2),
#endif
#if defined(NET_IPV4_TCP_FIN_TIMEOUT) || (defined(HAVE_DECL_NET_IPV4_TCP_FIN_TIMEOUT) && HAVE_DECL_NET_IPV4_TCP_FIN_TIMEOUT)
  XLAT(NET_IPV4_TCP_FIN_TIMEOUT),
#endif
#if defined(NET_IPV4_IP_MASQ_DEBUG) || (defined(HAVE_DECL_NET_IPV4_IP_MASQ_DEBUG) && HAVE_DECL_NET_IPV4_IP_MASQ_DEBUG)
  XLAT(NET_IPV4_IP_MASQ_DEBUG),
#endif
#if defined(NET_TCP_SYNCOOKIES) || (defined(HAVE_DECL_NET_TCP_SYNCOOKIES) && HAVE_DECL_NET_TCP_SYNCOOKIES)
  XLAT(NET_TCP_SYNCOOKIES),
#endif
#if defined(NET_TCP_STDURG) || (defined(HAVE_DECL_NET_TCP_STDURG) && HAVE_DECL_NET_TCP_STDURG)
  XLAT(NET_TCP_STDURG),
#endif
#if defined(NET_TCP_RFC1337) || (defined(HAVE_DECL_NET_TCP_RFC1337) && HAVE_DECL_NET_TCP_RFC1337)
  XLAT(NET_TCP_RFC1337),
#endif
#if defined(NET_TCP_SYN_TAILDROP) || (defined(HAVE_DECL_NET_TCP_SYN_TAILDROP) && HAVE_DECL_NET_TCP_SYN_TAILDROP)
  XLAT(NET_TCP_SYN_TAILDROP),
#endif
#if defined(NET_TCP_MAX_SYN_BACKLOG) || (defined(HAVE_DECL_NET_TCP_MAX_SYN_BACKLOG) && HAVE_DECL_NET_TCP_MAX_SYN_BACKLOG)
  XLAT(NET_TCP_MAX_SYN_BACKLOG),
#endif
#if defined(NET_IPV4_LOCAL_PORT_RANGE) || (defined(HAVE_DECL_NET_IPV4_LOCAL_PORT_RANGE) && HAVE_DECL_NET_IPV4_LOCAL_PORT_RANGE)
  XLAT(NET_IPV4_LOCAL_PORT_RANGE),
#endif
#if defined(NET_IPV4_ICMP_ECHO_IGNORE_ALL) || (defined(HAVE_DECL_NET_IPV4_ICMP_ECHO_IGNORE_ALL) && HAVE_DECL_NET_IPV4_ICMP_ECHO_IGNORE_ALL)
  XLAT(NET_IPV4_ICMP_ECHO_IGNORE_ALL),
#endif
#if defined(NET_IPV4_ICMP_ECHO_IGNORE_BROADCASTS) || (defined(HAVE_DECL_NET_IPV4_ICMP_ECHO_IGNORE_BROADCASTS) && HAVE_DECL_NET_IPV4_ICMP_ECHO_IGNORE_BROADCASTS)
  XLAT(NET_IPV4_ICMP_ECHO_IGNORE_BROADCASTS),
#endif
#if defined(NET_IPV4_ICMP_SOURCEQUENCH_RATE) || (defined(HAVE_DECL_NET_IPV4_ICMP_SOURCEQUENCH_RATE) && HAVE_DECL_NET_IPV4_ICMP_SOURCEQUENCH_RATE)
  XLAT(NET_IPV4_ICMP_SOURCEQUENCH_RATE),
#endif
#if defined(NET_IPV4_ICMP_DESTUNREACH_RATE) || (defined(HAVE_DECL_NET_IPV4_ICMP_DESTUNREACH_RATE) && HAVE_DECL_NET_IPV4_ICMP_DESTUNREACH_RATE)
  XLAT(NET_IPV4_ICMP_DESTUNREACH_RATE),
#endif
#if defined(NET_IPV4_ICMP_TIMEEXCEED_RATE) || (defined(HAVE_DECL_NET_IPV4_ICMP_TIMEEXCEED_RATE) && HAVE_DECL_NET_IPV4_ICMP_TIMEEXCEED_RATE)
  XLAT(NET_IPV4_ICMP_TIMEEXCEED_RATE),
#endif
#if defined(NET_IPV4_ICMP_PARAMPROB_RATE) || (defined(HAVE_DECL_NET_IPV4_ICMP_PARAMPROB_RATE) && HAVE_DECL_NET_IPV4_ICMP_PARAMPROB_RATE)
  XLAT(NET_IPV4_ICMP_PARAMPROB_RATE),
#endif
#if defined(NET_IPV4_ICMP_ECHOREPLY_RATE) || (defined(HAVE_DECL_NET_IPV4_ICMP_ECHOREPLY_RATE) && HAVE_DECL_NET_IPV4_ICMP_ECHOREPLY_RATE)
  XLAT(NET_IPV4_ICMP_ECHOREPLY_RATE),
#endif
#if defined(NET_IPV4_ICMP_IGNORE_BOGUS_ERROR_RESPONSES) || (defined(HAVE_DECL_NET_IPV4_ICMP_IGNORE_BOGUS_ERROR_RESPONSES) && HAVE_DECL_NET_IPV4_ICMP_IGNORE_BOGUS_ERROR_RESPONSES)
  XLAT(NET_IPV4_ICMP_IGNORE_BOGUS_ERROR_RESPONSES),
#endif
#if defined(NET_IPV4_IGMP_MAX_MEMBERSHIPS) || (defined(HAVE_DECL_NET_IPV4_IGMP_MAX_MEMBERSHIPS) && HAVE_DECL_NET_IPV4_IGMP_MAX_MEMBERSHIPS)
  XLAT(NET_IPV4_IGMP_MAX_MEMBERSHIPS),
#endif
#if defined(NET_TCP_TW_RECYCLE) || (defined(HAVE_DECL_NET_TCP_TW_RECYCLE) && HAVE_DECL_NET_TCP_TW_RECYCLE)
  XLAT(NET_TCP_TW_RECYCLE),
#endif
#if defined(NET_IPV4_ALWAYS_DEFRAG) || (defined(HAVE_DECL_NET_IPV4_ALWAYS_DEFRAG) && HAVE_DECL_NET_IPV4_ALWAYS_DEFRAG)
  XLAT(NET_IPV4_ALWAYS_DEFRAG),
#endif
#if defined(NET_IPV4_TCP_KEEPALIVE_INTVL) || (defined(HAVE_DECL_NET_IPV4_TCP_KEEPALIVE_INTVL) && HAVE_DECL_NET_IPV4_TCP_KEEPALIVE_INTVL)
  XLAT(NET_IPV4_TCP_KEEPALIVE_INTVL),
#endif
#if defined(NET_IPV4_INET_PEER_THRESHOLD) || (defined(HAVE_DECL_NET_IPV4_INET_PEER_THRESHOLD) && HAVE_DECL_NET_IPV4_INET_PEER_THRESHOLD)
  XLAT(NET_IPV4_INET_PEER_THRESHOLD),
#endif
#if defined(NET_IPV4_INET_PEER_MINTTL) || (defined(HAVE_DECL_NET_IPV4_INET_PEER_MINTTL) && HAVE_DECL_NET_IPV4_INET_PEER_MINTTL)
  XLAT(NET_IPV4_INET_PEER_MINTTL),
#endif
#if defined(NET_IPV4_INET_PEER_MAXTTL) || (defined(HAVE_DECL_NET_IPV4_INET_PEER_MAXTTL) && HAVE_DECL_NET_IPV4_INET_PEER_MAXTTL)
  XLAT(NET_IPV4_INET_PEER_MAXTTL),
#endif
#if defined(NET_IPV4_INET_PEER_GC_MINTIME) || (defined(HAVE_DECL_NET_IPV4_INET_PEER_GC_MINTIME) && HAVE_DECL_NET_IPV4_INET_PEER_GC_MINTIME)
  XLAT(NET_IPV4_INET_PEER_GC_MINTIME),
#endif
#if defined(NET_IPV4_INET_PEER_GC_MAXTIME) || (defined(HAVE_DECL_NET_IPV4_INET_PEER_GC_MAXTIME) && HAVE_DECL_NET_IPV4_INET_PEER_GC_MAXTIME)
  XLAT(NET_IPV4_INET_PEER_GC_MAXTIME),
#endif
#if defined(NET_TCP_ORPHAN_RETRIES) || (defined(HAVE_DECL_NET_TCP_ORPHAN_RETRIES) && HAVE_DECL_NET_TCP_ORPHAN_RETRIES)
  XLAT(NET_TCP_ORPHAN_RETRIES),
#endif
#if defined(NET_TCP_ABORT_ON_OVERFLOW) || (defined(HAVE_DECL_NET_TCP_ABORT_ON_OVERFLOW) && HAVE_DECL_NET_TCP_ABORT_ON_OVERFLOW)
  XLAT(NET_TCP_ABORT_ON_OVERFLOW),
#endif
#if defined(NET_TCP_SYNACK_RETRIES) || (defined(HAVE_DECL_NET_TCP_SYNACK_RETRIES) && HAVE_DECL_NET_TCP_SYNACK_RETRIES)
  XLAT(NET_TCP_SYNACK_RETRIES),
#endif
#if defined(NET_TCP_MAX_ORPHANS) || (defined(HAVE_DECL_NET_TCP_MAX_ORPHANS) && HAVE_DECL_NET_TCP_MAX_ORPHANS)
  XLAT(NET_TCP_MAX_ORPHANS),
#endif
#if defined(NET_TCP_MAX_TW_BUCKETS) || (defined(HAVE_DECL_NET_TCP_MAX_TW_BUCKETS) && HAVE_DECL_NET_TCP_MAX_TW_BUCKETS)
  XLAT(NET_TCP_MAX_TW_BUCKETS),
#endif
#if defined(NET_TCP_FACK) || (defined(HAVE_DECL_NET_TCP_FACK) && HAVE_DECL_NET_TCP_FACK)
  XLAT(NET_TCP_FACK),
#endif
#if defined(NET_TCP_REORDERING) || (defined(HAVE_DECL_NET_TCP_REORDERING) && HAVE_DECL_NET_TCP_REORDERING)
  XLAT(NET_TCP_REORDERING),
#endif
#if defined(NET_TCP_ECN) || (defined(HAVE_DECL_NET_TCP_ECN) && HAVE_DECL_NET_TCP_ECN)
  XLAT(NET_TCP_ECN),
#endif
#if defined(NET_TCP_DSACK) || (defined(HAVE_DECL_NET_TCP_DSACK) && HAVE_DECL_NET_TCP_DSACK)
  XLAT(NET_TCP_DSACK),
#endif
#if defined(NET_TCP_MEM) || (defined(HAVE_DECL_NET_TCP_MEM) && HAVE_DECL_NET_TCP_MEM)
  XLAT(NET_TCP_MEM),
#endif
#if defined(NET_TCP_WMEM) || (defined(HAVE_DECL_NET_TCP_WMEM) && HAVE_DECL_NET_TCP_WMEM)
  XLAT(NET_TCP_WMEM),
#endif
#if defined(NET_TCP_RMEM) || (defined(HAVE_DECL_NET_TCP_RMEM) && HAVE_DECL_NET_TCP_RMEM)
  XLAT(NET_TCP_RMEM),
#endif
#if defined(NET_TCP_APP_WIN) || (defined(HAVE_DECL_NET_TCP_APP_WIN) && HAVE_DECL_NET_TCP_APP_WIN)
  XLAT(NET_TCP_APP_WIN),
#endif
#if defined(NET_TCP_ADV_WIN_SCALE) || (defined(HAVE_DECL_NET_TCP_ADV_WIN_SCALE) && HAVE_DECL_NET_TCP_ADV_WIN_SCALE)
  XLAT(NET_TCP_ADV_WIN_SCALE),
#endif
#if defined(NET_IPV4_NONLOCAL_BIND) || (defined(HAVE_DECL_NET_IPV4_NONLOCAL_BIND) && HAVE_DECL_NET_IPV4_NONLOCAL_BIND)
  XLAT(NET_IPV4_NONLOCAL_BIND),
#endif
#if defined(NET_IPV4_ICMP_RATELIMIT) || (defined(HAVE_DECL_NET_IPV4_ICMP_RATELIMIT) && HAVE_DECL_NET_IPV4_ICMP_RATELIMIT)
  XLAT(NET_IPV4_ICMP_RATELIMIT),
#endif
#if defined(NET_IPV4_ICMP_RATEMASK) || (defined(HAVE_DECL_NET_IPV4_ICMP_RATEMASK) && HAVE_DECL_NET_IPV4_ICMP_RATEMASK)
  XLAT(NET_IPV4_ICMP_RATEMASK),
#endif
#if defined(NET_TCP_TW_REUSE) || (defined(HAVE_DECL_NET_TCP_TW_REUSE) && HAVE_DECL_NET_TCP_TW_REUSE)
  XLAT(NET_TCP_TW_REUSE),
#endif
#if defined(NET_TCP_FRTO) || (defined(HAVE_DECL_NET_TCP_FRTO) && HAVE_DECL_NET_TCP_FRTO)
  XLAT(NET_TCP_FRTO),
#endif
#if defined(NET_TCP_LOW_LATENCY) || (defined(HAVE_DECL_NET_TCP_LOW_LATENCY) && HAVE_DECL_NET_TCP_LOW_LATENCY)
  XLAT(NET_TCP_LOW_LATENCY),
#endif
#if defined(NET_IPV4_IPFRAG_SECRET_INTERVAL) || (defined(HAVE_DECL_NET_IPV4_IPFRAG_SECRET_INTERVAL) && HAVE_DECL_NET_IPV4_IPFRAG_SECRET_INTERVAL)
  XLAT(NET_IPV4_IPFRAG_SECRET_INTERVAL),
#endif
#if defined(NET_IPV4_IGMP_MAX_MSF) || (defined(HAVE_DECL_NET_IPV4_IGMP_MAX_MSF) && HAVE_DECL_NET_IPV4_IGMP_MAX_MSF)
  XLAT(NET_IPV4_IGMP_MAX_MSF),
#endif
#if defined(NET_TCP_NO_METRICS_SAVE) || (defined(HAVE_DECL_NET_TCP_NO_METRICS_SAVE) && HAVE_DECL_NET_TCP_NO_METRICS_SAVE)
  XLAT(NET_TCP_NO_METRICS_SAVE),
#endif
#if defined(NET_TCP_DEFAULT_WIN_SCALE) || (defined(HAVE_DECL_NET_TCP_DEFAULT_WIN_SCALE) && HAVE_DECL_NET_TCP_DEFAULT_WIN_SCALE)
  XLAT(NET_TCP_DEFAULT_WIN_SCALE),
#endif
#if defined(NET_TCP_MODERATE_RCVBUF) || (defined(HAVE_DECL_NET_TCP_MODERATE_RCVBUF) && HAVE_DECL_NET_TCP_MODERATE_RCVBUF)
  XLAT(NET_TCP_MODERATE_RCVBUF),
#endif
#if defined(NET_TCP_TSO_WIN_DIVISOR) || (defined(HAVE_DECL_NET_TCP_TSO_WIN_DIVISOR) && HAVE_DECL_NET_TCP_TSO_WIN_DIVISOR)
  XLAT(NET_TCP_TSO_WIN_DIVISOR),
#endif
#if defined(NET_TCP_BIC_BETA) || (defined(HAVE_DECL_NET_TCP_BIC_BETA) && HAVE_DECL_NET_TCP_BIC_BETA)
  XLAT(NET_TCP_BIC_BETA),
#endif
#if defined(NET_IPV4_ICMP_ERRORS_USE_INBOUND_IFADDR) || (defined(HAVE_DECL_NET_IPV4_ICMP_ERRORS_USE_INBOUND_IFADDR) && HAVE_DECL_NET_IPV4_ICMP_ERRORS_USE_INBOUND_IFADDR)
  XLAT(NET_IPV4_ICMP_ERRORS_USE_INBOUND_IFADDR),
#endif
#if defined(NET_TCP_CONG_CONTROL) || (defined(HAVE_DECL_NET_TCP_CONG_CONTROL) && HAVE_DECL_NET_TCP_CONG_CONTROL)
  XLAT(NET_TCP_CONG_CONTROL),
#endif
#if defined(NET_TCP_ABC) || (defined(HAVE_DECL_NET_TCP_ABC) && HAVE_DECL_NET_TCP_ABC)
  XLAT(NET_TCP_ABC),
#endif
#if defined(NET_IPV4_IPFRAG_MAX_DIST) || (defined(HAVE_DECL_NET_IPV4_IPFRAG_MAX_DIST) && HAVE_DECL_NET_IPV4_IPFRAG_MAX_DIST)
  XLAT(NET_IPV4_IPFRAG_MAX_DIST),
#endif
#if defined(NET_TCP_MTU_PROBING) || (defined(HAVE_DECL_NET_TCP_MTU_PROBING) && HAVE_DECL_NET_TCP_MTU_PROBING)
  XLAT(NET_TCP_MTU_PROBING),
#endif
#if defined(NET_TCP_BASE_MSS) || (defined(HAVE_DECL_NET_TCP_BASE_MSS) && HAVE_DECL_NET_TCP_BASE_MSS)
  XLAT(NET_TCP_BASE_MSS),
#endif
#if defined(NET_IPV4_TCP_WORKAROUND_SIGNED_WINDOWS) || (defined(HAVE_DECL_NET_IPV4_TCP_WORKAROUND_SIGNED_WINDOWS) && HAVE_DECL_NET_IPV4_TCP_WORKAROUND_SIGNED_WINDOWS)
  XLAT(NET_IPV4_TCP_WORKAROUND_SIGNED_WINDOWS),
#endif
#if defined(NET_TCP_DMA_COPYBREAK) || (defined(HAVE_DECL_NET_TCP_DMA_COPYBREAK) && HAVE_DECL_NET_TCP_DMA_COPYBREAK)
  XLAT(NET_TCP_DMA_COPYBREAK),
#endif
#if defined(NET_TCP_SLOW_START_AFTER_IDLE) || (defined(HAVE_DECL_NET_TCP_SLOW_START_AFTER_IDLE) && HAVE_DECL_NET_TCP_SLOW_START_AFTER_IDLE)
  XLAT(NET_TCP_SLOW_START_AFTER_IDLE),
#endif
#if defined(NET_CIPSOV4_CACHE_ENABLE) || (defined(HAVE_DECL_NET_CIPSOV4_CACHE_ENABLE) && HAVE_DECL_NET_CIPSOV4_CACHE_ENABLE)
  XLAT(NET_CIPSOV4_CACHE_ENABLE),
#endif
#if defined(NET_CIPSOV4_CACHE_BUCKET_SIZE) || (defined(HAVE_DECL_NET_CIPSOV4_CACHE_BUCKET_SIZE) && HAVE_DECL_NET_CIPSOV4_CACHE_BUCKET_SIZE)
  XLAT(NET_CIPSOV4_CACHE_BUCKET_SIZE),
#endif
#if defined(NET_CIPSOV4_RBM_OPTFMT) || (defined(HAVE_DECL_NET_CIPSOV4_RBM_OPTFMT) && HAVE_DECL_NET_CIPSOV4_RBM_OPTFMT)
  XLAT(NET_CIPSOV4_RBM_OPTFMT),
#endif
#if defined(NET_CIPSOV4_RBM_STRICTVALID) || (defined(HAVE_DECL_NET_CIPSOV4_RBM_STRICTVALID) && HAVE_DECL_NET_CIPSOV4_RBM_STRICTVALID)
  XLAT(NET_CIPSOV4_RBM_STRICTVALID),
#endif
#if defined(NET_TCP_AVAIL_CONG_CONTROL) || (defined(HAVE_DECL_NET_TCP_AVAIL_CONG_CONTROL) && HAVE_DECL_NET_TCP_AVAIL_CONG_CONTROL)
  XLAT(NET_TCP_AVAIL_CONG_CONTROL),
#endif
#if defined(NET_TCP_ALLOWED_CONG_CONTROL) || (defined(HAVE_DECL_NET_TCP_ALLOWED_CONG_CONTROL) && HAVE_DECL_NET_TCP_ALLOWED_CONG_CONTROL)
  XLAT(NET_TCP_ALLOWED_CONG_CONTROL),
#endif
#if defined(NET_TCP_MAX_SSTHRESH) || (defined(HAVE_DECL_NET_TCP_MAX_SSTHRESH) && HAVE_DECL_NET_TCP_MAX_SSTHRESH)
  XLAT(NET_TCP_MAX_SSTHRESH),
#endif
#if defined(NET_TCP_FRTO_RESPONSE) || (defined(HAVE_DECL_NET_TCP_FRTO_RESPONSE) && HAVE_DECL_NET_TCP_FRTO_RESPONSE)
  XLAT(NET_TCP_FRTO_RESPONSE),
#endif
 XLAT_END
};

#endif /* !IN_MPERS */
