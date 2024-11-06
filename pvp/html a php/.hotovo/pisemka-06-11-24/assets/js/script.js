document.addEventListener('DOMContentLoaded', function() {
    function updateTime() {
        const now = new Date();
        document.getElementById('current-time').textContent =
            now.toLocaleTimeString('cs-CZ', {
                hour: '2-digit',
                minute: '2-digit',
                second: '2-digit'
            });
    }

    updateTime();
    setInterval(updateTime, 1000);
});