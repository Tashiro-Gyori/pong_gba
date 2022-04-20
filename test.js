const {Builder, By} = require('selenium-webdriver');
const firefox = require('selenium-webdriver/firefox');

let options = new firefox.Options();
options.setPreference("browser.download.folderList", 1); // download to folder Downloads
options.setPreference("browser.helperApps.neverAsk.saveToDisk", "application/octet-stream");

// Instanciation of Firefox web driver (geckodriver)
const driver = new Builder().forBrowser('firefox').setFirefoxOptions(options).build();
driver.get('https://tashiro-gyori.github.io/pong_gba/'); // prob ici : teste la branche master...
driver.findElement(By.id('screenshot-btn')).then(async btn => {
    btn.click();
    try {
        driver.navigate().to("file:///home/ubuntu/Downloads/screenshot.png");
        let file1 = await driver.getPageSource();
        driver.navigate().to("https://raw.githubusercontent.com/Tashiro-Gyori/pong_gba/master/tests/0.png");
        let file2 = await driver.getPageSource();
        if (file1 === file2)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    } catch (error) {
        console.error(error);
    }
});
