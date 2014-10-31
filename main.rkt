#lang racket/base

(require "ometa.scm")

(provide *ometa-debug*

	 parse-position>?
	 top-file-parse-position
	 update-file-parse-position

	 merge-parse-errors
	 make-parse-error

	 input-stream-cons
	 input-stream-position
	 input-stream-append
	 ->input-stream-or-false
	 ->input-stream
	 register-input-stream-constructor!

	 input-stream-split-at-most
	 input-stream->list

	 make-port-input-stream
	 current-input-stream

	 ometa-namespace-getter

	 meta-ometa

	 serialize-ometa-ast

	 format-ometa-error
	 report-ometa-error

	 parse-ometa
	 parse-ometa-file

	 ometa-library-path

	 opt

	 merge-ometa

	 load-ometa
	 simple-ometa-driver
	 interpret-ometa ;; use simple-ometa-driver instead
	 )
