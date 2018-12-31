#!/bin/bash

. ../lib/base_libs.sh 2>&1

log "This is a test\n"
success "All Test"
log "Maybe is"
highlight_words "please check network\n"
fail "Get first name"
