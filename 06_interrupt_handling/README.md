# Interrupt Handling

1. Write a kernel module that registers an interrupt handler for a software interrupt (e.g., using `request_irq` on a free IRQ line, if available, or simulate with a timer).
2. Load the module and monitor periodic interrupts via `dmesg`.
3. Experiment with changing the timer interval and observe effects.

# Resources

- [Interrupts Example Program in Linux Kernel](https://embetronicx.com/tutorials/linux/device-drivers/linux-device-driver-tutorial-part-13-interrupt-example-program-in-linux-kernel/)
- [LDD3 Chapter 10](https://www.oreilly.com/library/view/linux-device-drivers/0596005903/ch10.html)
- [`request_irq` returns error code -16](https://stackoverflow.com/questions/61462055/interrupt-handler-request-irq-returns-error-code-16)
- [`request_irq` returns error code -22](https://stackoverflow.com/questions/15245626/simple-interrupt-handler-request-irq-returns-error-code-22)
- [Difference between `IO_APIC-fasteoi` and `IO_APIC_edge`](https://stackoverflow.com/questions/7005331/difference-between-io-apic-fasteoi-and-io-apic-edge)
