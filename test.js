const {Builder, By} = require('selenium-webdriver');
const firefox = require('selenium-webdriver/firefox');

let options = new firefox.Options()
options.addPreference("browser.download.folderList", 1); // download to folder Downloads
options.addPreference("browser.helperApps.neverAsk.saveToDisk", "application/octet-stream");

// Instanciation of Firefox web driver (geckodriver)
const driver = new Builder().forBrowser('firefox').setFirefoxOptions(options).build();
driver.get('https://tashiro-gyori.github.io/pong_gba/'); // prob ici : teste la branche master...
driver.findElement(By.id('screenshot-btn')).then(btn => {
    btn.click();

    driver.Navigate().GoToUrl("file:///home/ubuntu/Downloads/screenshot.png");
    let file1 = driver.PageSource;
    driver.Navigate().GoToUrl("https://raw.githubusercontent.com/Tashiro-Gyori/pong_gba/dev/tests/0.png"); // a changer après merge
    let file2 = driver.PageSource;
    if (file1.Equals(file2))
    {
        return 0;
    }
    else
    {
        return 1;
    }
});
