document.addEventListener("DOMContentLoaded", function () {
    // 1. DONUT CHART (Ringkasan Proyek)
    const ctxDonut = document.getElementById('donutChart').getContext('2d');
    new Chart(ctxDonut, {
        type: 'doughnut',
        data: {
            labels: ['Dalam Proses', 'Menunggu Revisi', 'Selesai', 'Dibatalkan'],
            datasets: [{
                data: [12, 6, 4, 2],
                backgroundColor: [
                    '#6366F1', // Indigo / Purple
                    '#3B82F6', // Blue
                    '#F59E0B', // Amber / Orange
                    '#10B981'  // Emerald / Green
                ],
                borderWidth: 0,
                weight: 0.5
            }]
        },
        options: {
            responsive: true,
            maintainAspectRatio: false,
            cutout: '78%',
            plugins: {
                legend: {
                    display: false // Menggunakan legend kustom HTML di kanan
                },
                tooltip: {
                    enabled: true
                }
            }
        }
    });

    // 2. LINE CHART (Pendapatan)
    const ctxLine = document.getElementById('lineChart').getContext('2d');
    
    // Membuat efek gradasi warna ungu transparan di bawah garis grafik
    const gradient = ctxLine.createLinearGradient(0, 0, 0, 140);
    gradient.addColorStop(0, 'rgba(99, 102, 241, 0.35)');
    gradient.addColorStop(1, 'rgba(99, 102, 241, 0.00)');

    new Chart(ctxLine, {
        type: 'line',
        data: {
            labels: ['1 Mei', '8 Mei', '15 Mei', '22 Mei', '29 Mei', '31 Mei'],
            datasets: [{
                label: 'Pendapatan',
                data: [5, 12, 25, 16, 18, 24.75], // dalam jutaan
                borderColor: '#6366F1',
                borderWidth: 2.5,
                pointBackgroundColor: '#6366F1',
                pointBorderColor: '#fff',
                pointBorderWidth: 2,
                pointRadius: 4,
                pointHoverRadius: 6,
                tension: 0.4, // Membuat garis melengkung lembut halus
                fill: true,
                backgroundColor: gradient
            }]
        },
        options: {
            responsive: true,
            maintainAspectRatio: false,
            plugins: {
                legend: {
                    display: false
                },
                tooltip: {
                    callbacks: {
                        label: function(context) {
                            return ' Rp ' + (context.raw * 1000000).toLocaleString('id-ID');
                        }
                    }
                }
            },
            scales: {
                x: {
                    grid: {
                        display: false
                    },
                    ticks: {
                        font: {
                            size: 9,
                            family: 'Plus Jakarta Sans'
                        },
                        color: '#94A3B8'
                    }
                },
                y: {
                    min: 0,
                    max: 40,
                    ticks: {
                        stepSize: 10,
                        callback: function(value) {
                            return value + 'jt';
                        },
                        font: {
                            size: 9,
                            family: 'Plus Jakarta Sans'
                        },
                        color: '#94A3B8'
                    },
                    grid: {
                        color: '#F1F5F9'
                    },
                    border: {
                        dash: [5, 5]
                    }
                }
            }
        }
    });
});
