const ctx = document.getElementById('donationChart').getContext('2d');
const donationChart = new Chart(ctx, {
  type: 'doughnut',
  data: {
    labels: [
      'Organizing Events',
      'Skills Training',
      'Human Safety',
      'Helping People',
      'Feeding the Poor'
    ],
    datasets: [{
      data: [40, 35, 10, 10, 5],
      backgroundColor: [
        '#98FB98', // Light Green
        '#9370DB', // Medium Purple
        '#FFD700', // Gold
        '#FFA07A', // Light Salmon
        '#FFB6C1'  // Light Pink
      ],
      hoverOffset: 4
    }]
  },
  options: {
    responsive: true,
    plugins: {
      legend: {
        display: false
      },
      tooltip: {
        callbacks: {
          label: function(tooltipItem) {
            return tooltipItem.label + ': ' + tooltipItem.raw + '%';
          }
        }
      }
    },
    cutout: '70%'
  }
});
